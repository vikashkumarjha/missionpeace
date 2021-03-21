/*

A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "111" can have each of its "1"s be mapped into 'A's to make "AAA", or it could be mapped to "11" and "1" ('K' and 'A' respectively) to make "KA". Note that "06" cannot be mapped into 'F' since "6" is different from "06".

Given a non-empty string num containing only digits, return the number of ways to decode it.


*/

#include "../header.hpp"


int helper(string &s, int idx) {
    if ( idx == 0  ) {
        return 1;
    }

    int count = 0;

    if ( s[idx - 1] != '0') {
        count = helper(s, idx - 1);
    }

    if (s[idx-2] == '1' || (s[idx-2] == '2' && s[idx-1] < '7')) {
        count += helper(s, idx-2);
    }

    return count;

}


int numDecodings(string s) {
    if ( s.empty() || s[0] == '0') return 0;
    int n = s.size();
    return helper(s, n);

}


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




int main()
{
    string digits = "1234";
    cout << "The number of decodings" << numDecodings(digits);
    return 0;
}