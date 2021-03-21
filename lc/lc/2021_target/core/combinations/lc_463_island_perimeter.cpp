/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

*/

class Solution {
    bool countEdge(vector<vector<int>>& grid , int i , int j){
        if ( i < 0 || j < 0 || i == grid.size() || j == grid[i].size())
            return true;
        return grid[i][j] == 0;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if ( grid.size() == 0 ) return 0;
        int m = grid.size();
        int result = 0;
        for ( int i = 0; i < m; i++){
            for ( int j = 0; j < grid[i].size(); j++){
                if ( grid[i][j] == 1){
                    result += (countEdge(grid,i-1,j)) ? 1 : 0;
                    result += (countEdge(grid,i,j-1)) ? 1 : 0;
                    result += (countEdge(grid,i+1,j)) ? 1 : 0;
                    result += (countEdge(grid,i,j+1)) ? 1 : 0;
                }
            }
        }
        return result;
    }
};