/*
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;





class Solution {
private:
    unordered_map<int,int> m;
    int helper( int idx, string &s) {
        if ( m.count(idx)) {
            return m[idx];
        }
        if ( idx >= s.size() - 1) {
            return 1; 
        }
        if ( s[idx] == '0') {
            return 0;
        } 

        int subResult = helper(idx+1, s);
        int d = stoi(s.substr(idx,2));
        if ( d >= 1 && d <= 26) {
            subResult += helper(idx+2, s);
        }
        m[idx] = subResult;
        return subResult;
    }
public:
    int numDecodings(string s) {
            if ( s.empty()) return 0;
                return helper(0, s);
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if ( s.empty() || s[0] == '0') {
            return 0;
        }
        
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        
        dp[0] = 1;
        
        for ( int i = 1; i <= n; i++) {
            if ( s[i-1] != '0') {
                dp[i] = dp[i-1];
            }
            if ( i >= 2) {
                int v = stoi(s.substr(i-2, 2));
                if ( v > 9 && v <= 26) {
                    dp[i] += dp[i-2];
                }
            }
            
        }
        
        return dp[n];
        
        
    }
}; 