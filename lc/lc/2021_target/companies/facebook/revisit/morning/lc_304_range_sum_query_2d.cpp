class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if ( matrix.empty()) return;
        
        R = matrix.size();
        C = matrix[0].size();
        dp = vector<vector<int>>(R+1, vector<int>(C+1,0));
        
        for ( int r = 1; r <= R; r++) {
            for ( int c = 1; c <= C; c++) {
                
                dp[r][c] = matrix[r-1][c-1] + dp[r-1][c] + dp[r][c-1] - dp[r-1][c-1];
                
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        for ( int i = 0; i <= R; i++) {
            
            cout << "\n";
            
            for ( int j = 0; j <= C; j++){
                cout << dp[i][j] << " ";
            }
        }
        
        
        //cout << "\n" <<  dp[row2+1][col2+1] << "::" <<dp[row2+1][col1] << "::" << dp[row1][col2+1] << "::" << dp[row1][col1];
        
      
        int val = dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1]+ dp[row1][col1];
        
        return val;
        
    }
 
 private:
    int R;
    int C;
    vector<vector<int>> dp;
    
    
};