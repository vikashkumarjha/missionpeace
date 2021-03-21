
/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

*/


class Solution {
public:
    int DFS(vector<vector<int>> & matrix, int i, int j, int prevValue, vector<vector<int>> & grid) {
        int R = matrix.size();
        int C = matrix[0].size();
           
        if (i < 0 || i >= R|| j < 0 || j >= C)
            return 0;
       
        if (matrix[i][j] > prevValue) {
            if (grid[i][j] != 0) return grid[i][j];
           
            int maxPath = 0;
           
            vector<vector<int>> DIRS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for (int k = 0; k < DIRS.size(); k++) {
                int path = DFS(matrix, i + DIRS[k][0], j + DIRS[k][1], matrix[i][j], grid) + 1;
                maxPath  = max(maxPath, path);
            }
           
            grid[i][j] = maxPath;
            return grid[i][j];
        }
       
        return 0;
    }
   
    int longestIncreasingPath(vector<vector<int>> & matrix) {
        if (matrix.empty())  return 0;
       
        int globalMaxpath = 0;
       
        int R = matrix.size();
        int C = matrix[0].size();
           
        vector<vector<int>> grid(R, vector<int>(C, 0));

        for(int i = 0; i< R; i++)
            for(int j = 0; j < C; j++)
                globalMaxpath = max(DFS(matrix, i, j, INT_MIN, grid), globalMaxpath);
       
        return globalMaxpath;
    }
};
