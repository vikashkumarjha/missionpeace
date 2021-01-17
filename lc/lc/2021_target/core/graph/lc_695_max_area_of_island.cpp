/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

 */

#include "../../header.hpp"

class Solution {
public:
    int MAXCOL;
    int MAXROW;
    
    
    void dfs(vector<vector<int>> &g, int r, int c, int &area) {
        area++;
        g[r][c] = 0;
        vector<vector<int>> DIRS = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for ( auto d : DIRS) {
            int x = r + d[0];
            int y = c + d[1];
            
            if ( x >= 0 && x < MAXROW && y >= 0 && y < MAXCOL && g[x][y] == 1) {
                dfs(g, x, y, area);
            }
            
        }
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if ( grid.empty()) 
            return 0;
        
        int R = grid.size();
        int C = grid[0].size();
        MAXROW = R;
        MAXCOL = C;
        
        int res = 0;
        
        for ( int r = 0; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                if ( grid[r][c] == 1) {
                    int area = 0;
                    dfs(grid, r, c, area);
                    res = max(area, res);     
                }
            }
            
        }
        
        return res;
        
    }
};