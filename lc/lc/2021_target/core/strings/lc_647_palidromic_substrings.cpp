/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

*/


class Solution {
public:
    int countSubstrings(string s) {
        if ( s.empty()) {
            return 0;
        }
        int n = s.size();
        int pallinCount = 0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for ( int l = 1; l <= n; l++ ) 
        {
            if ( l == 1) {
                for ( int i = 1; i <= n; i++) {
                    dp[i][i] = 1;
                    pallinCount++;
                }
                
                
            }else if (l == 2) {
                
                for ( int i = 1; i < n; i++) {
                    if ( s[i] == s[i-1]) {
                        dp[i][i+1] = 1;
                        pallinCount++;
                    }
                }
            } else {
                for ( int i = 1; i <= n - l + 1; i++) {
                    int j = i + l - 1;
                    if (dp[i+1][j-1] && s[i-1] == s[j-1]) {
                        dp[i][j] = 1;
                        pallinCount++;
                    }
                }
                
            }
            
        }
        
        return pallinCount;
     
    }
};