/*

1 2 3
4 5 6
7 8 9

// dp[i][j] = matrix[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
0 0 0 0 
0 1 3 6 
0 5 12 21 
0 12 27 45 


for [1,1,2,2]
//45 - 12 - 6 + 1

*/
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if ( matrix.empty()) return;

        int R = matrix.size();
        int C = matrix[0].size();
        dp = vector<vector<int>>(R+1, vector<int>(C+1));

        for ( int r = 1; r <= R; r++) {
            for ( int c = 1; c <= C; c++) {
                dp[r][c] = matrix[r-1][c-1] + dp[r-1][c] + dp[r][c-1] - dp[r-1][c-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
        
    }
private:
    vector<vector<int>> dp;

};

