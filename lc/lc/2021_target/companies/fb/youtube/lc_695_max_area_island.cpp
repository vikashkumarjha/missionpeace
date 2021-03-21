//
//  lc_695_max_area_island.cpp
//  lc
//
//  Created by vikash kumar jha on 3/1/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0

#include "header.hpp"

using namespace std;


void dfs( vector<vector<int>> &grid, int i , int j, int &area) {
    int R = grid.size();
    int C = grid[0].size();
    
    vector<vector<int>> DIRS = { {-1, 0}, {1,0}, {0,1}, {0,-1}};
    if ( i >= 0 && i < R && j >= 0 && j < C; grid[i][j]) {
        area++;
        grid[i][j] = 0;
        for ( int k = 0; k < DIRS.size(); k++) {
            dfs( grid, i + DIRS[k][0], j + DIRS[k][1], area);
        }
    }
      
}







 int maxAreaOfIsland(vector<vector<int>>& grid) {
     int R = grid.size();
     int C = grid[0].size();
     
     int maxArea = 0;
     for ( int i = 0; i < R; i++) {
         for ( int j = 0; j < C; j++) {
             if ( grid[i][j] == 1) {
                 int area = 0;
                 dfs(grid, i, j, area);
                 maxArea = max(maxArea, area);
             }
             
         }
     }
     
     return maxArea;
     
 }


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M = grid.size(), curMaxArea = 0;
        int N = grid[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    curMaxArea = max(dfs(grid, i, j), curMaxArea);
                }
            }
        }
        return curMaxArea;
    }
    
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 0;
        }
        grid[x][y] = 0;
        int area = 1;
        area += dfs(grid, x + 1, y);
        area += dfs(grid, x - 1, y);
        area += dfs(grid, x, y + 1);
        area += dfs(grid, x, y - 1);
        return area;
    }
};

#endif






