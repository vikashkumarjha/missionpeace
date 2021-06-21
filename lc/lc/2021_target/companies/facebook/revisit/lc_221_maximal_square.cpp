class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        if (mat.empty()) return 0;
        int R = mat.size();
        int C = mat[0].size();
        
        vector<vector<int>> dp(R+1, vector<int>(C+1, 0));
        int maxLen = 0;
        
        for ( int r = 0; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                if ( r == 0 || c == 0) {
                    dp[r][c] = mat[r][c] - '0';
                   
                }
                else {
                    if ( mat[r][c] == '1') {
                        dp[r][c] = min(dp[r-1][c], min(dp[r][c-1], dp[r-1][c-1])) + 1;
                    }
                }
                 maxLen = max(maxLen, dp[r][c]); 
            }
        }
        return maxLen * maxLen;
        
    }
};