/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;
       
        int R = matrix.size();
        int C = matrix[0].size();
        
        
        // dp(i,j) => numner of squares at 
        
        /*[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
     if matrix[i][j] == 1 then
    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
    else 
      dp[i][j] = 0;
    

*/
       
        vector<vector<int>> dp(R, vector<int>(C, 0));
       
        for (int i = 0; i < R; i++)
            dp[i][0] = matrix[i][0];
       
        for (int i = 0; i < C; i++)
            dp[0][i] = matrix[0][i];
       
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[i][j] == 0)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                }
            }
        }
       
        int countSquare = 0;
        for (int i = 0; i < dp.size(); i++)
             countSquare += accumulate(dp[i].begin(), dp[i].end(), 0);
       
        return countSquare;
    }
};