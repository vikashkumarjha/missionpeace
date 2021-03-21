/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number on the row below.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

*/

/*************************************************************************************
   [2, 0, 0, 0],
   [3, 4, 0, 0],
   [6, 5, 7, 0],
   [4, 1, 8, 3]
   

// Intermidiate Traingle values.
2
5 6
11 10 13
15 11 18 16
   
*************************************************************************************/

class Solution {
public:
    int minimumTotal(vector<vector<int>> & triangle) {
        int ROW = triangle.size();
       
        for (int i = 1; i < ROW; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0)
                {
                    triangle[i][j] += triangle[i - 1][j];
                }
                else if (j == triangle[i].size() - 1)
                {
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else
                {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
       
       
        int minPathSum = triangle[ROW - 1][0];
        for (int i = 0; i < triangle[ROW - 1].size(); ++i)
        {
            minPathSum = min(minPathSum, triangle[ROW - 1][i]);
        }
       
        return minPathSum;
    }
};
