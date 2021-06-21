class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        int startIdx = -1;
        int maxLen = 0;
        int count = 0;
        
        for ( int len = 1; len <= n; len++) {
            
            if ( len == 1) {
                for ( int i = 1; i <= n; i++){
                    dp[i][i] = 1;
                    startIdx = i - 1;
                    maxLen = len;
                    count++;
                }
                
            }
            else if ( len == 2) {
                for ( int i = 1; i <= n; i++) {
                    if ( s[i-1] == s[i] ) {
                        dp[i][i+1] = 1;
                        startIdx = i - 1;
                        maxLen = 2;
                        count++;
                    }
                }
            }
            else {
                for ( int i = 1; i <= (n - len + 1); i++) {
                    int j = i + len - 1;
                    
                    if ( s[i-1] == s[j-1] && dp[i+1][j-1]) {
                        startIdx = i - 1;
                        maxLen = len;
                        dp[i][j] = 1;
                        count++;
                    }
                    
                }
                
            }
        
        }
        return count;
        
        
    }
};