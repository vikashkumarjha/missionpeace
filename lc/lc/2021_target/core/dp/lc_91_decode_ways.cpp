/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

*/

#include "../header.hpp"

class Solution1 {
private:
    unordered_map<int,int> m;
    int helper(int idx, string &s) {
        
        if ( m.count(idx)) return m[idx];
        
        if (s[idx] == '0') return 0;
       
        if ( idx >= s.length() - 1) {
            return 1;
        }


        int subResult = helper(idx + 1, s);
        if ( stoi(s.substr(idx ,2)) >= 1 && stoi(s.substr(idx , 2)) <= 26 ) {
            subResult += helper(idx+2, s);
        }
        m[idx] = subResult;
        return subResult;
    }
public:
    int numDecodings(string s) {
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