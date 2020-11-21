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