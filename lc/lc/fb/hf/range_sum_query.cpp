class NumMatrix {
    vector<vector<int>> dp;
   
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
           
        int R = matrix.size();
        int C = matrix[0].size();
       
        dp = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));
       
        for (int i = 1; i <= R; i++)
             for (int j = 1; j <= C; j++) {
                 int cumSum1 = dp[i - 1][j];
                 int cumSum2 = dp[i][j - 1];
                 
                 int commonSum = dp[i - 1][j - 1];
               
                 dp[i][j] = matrix[i - 1][j - 1] + (cumSum1 + cumSum2 - commonSum);
             }
                 
                 
    }
   
    int sumRegion(int row1, int col1, int row2, int col2) {
           int cumSum1 =  dp[row2 + 1][col1];
           int cumSum2 =  dp[row1][col2 + 1];
           int commonSum = dp[row1][col1];
               
           return dp[row2 + 1][col2 + 1] - cumSum1 - cumSum2 + commonSum;
    }
};
