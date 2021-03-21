/*
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/


class Solution {
  public:

    void dfs(vector<vector<char>> &g, int r, int c) {
      int R = g.size();
      int C = g[0].size();

      g[r][c] = 0;

      vector<vector<int>> DIRS = {{0,1}, {1, 0}, {-1,0}, {0,-1}};
      for ( auto d : DIRS) {
        int x = r + d[0];
        int y = c + d[1];

        if ( x >= 0 && x < R && y >= 0 && y < C) {
          if ( g[x][y] == '1') {
            dfs(g, x, y);
          }
        }
      }

    }



    int numIslands(vector<vector<char>>& grid) {

      int res = 0;
      if ( grid.empty()) return 0;

      int R = grid.size();
      int C = grid[0].size();

      for ( int r = 0; r < R; r++) {
        for ( int c = 0; c < C; c++) {
          if ( grid[r][c] == '1') {
            res += 1;
            dfs(grid, r, c);
          }
        }
      }

      return res;


    }
};
