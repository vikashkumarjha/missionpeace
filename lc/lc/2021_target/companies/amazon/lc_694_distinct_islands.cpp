/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Count the number of distinct islands. An island is considered to be the same as another if and only if one island can be translated (and not rotated or reflected) to equal the other.

Example 1:
11000
11000
00011
00011
Given the above grid map, return 1.
Example 2:
11011
10000
00001
11011

*/

#include "header.hpp"


class Solution {
public:
   
void dfs(vector<vector<int>>& grid, int i, int j, string &path, char dir){
    if ( i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
        return;
    }
    
    path.push_back(dir);
    grid[i][j] = 0;
    
    dfs(grid, i+1, j, path, 'd');
    dfs(grid, i, j+1, path, 'r');
    dfs(grid, i-1, j, path, 'u');
    dfs(grid, i, j-1, path, 'l');
    path.push_back('b');
    
}




int numDistinctIslands(vector<vector<int>>& grid) {
    
    int n = grid.size();
    if ( n == 0)
        return 0;
    int m = grid[0].size();
    
    unordered_set<string> islands;
    
    
    for ( int i = 0; i < n; i++){
        for ( int j = 0; j < m; j++){
            if ( grid[i][j] == 1){
                string path;
                dfs(grid, i, j, path, 'o');
                if ( !path.empty())
                    islands.insert(path);
            }
        }
    }
    
    return islands.size(); 
    
    
}
};