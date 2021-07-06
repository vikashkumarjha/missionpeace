class Solution {

public:

    void dfs(vector<vector<int>> &g, int r, int c, int &area) {
        area++;
        g[r][c] = 0;
        vector<vector<int>> DIRS = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        for ( auto d : DIRS) {
            int x = r + d[0];
            int y = c + d[1];
            if ( x >= 0 && x < g.size() && y >= 0 && y < g[0].size()) {
                if ( g[x][y] == 1) {
                    dfs(g, x,y, area);
                }
            }
        }

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if ( grid.empty()) return 0;
        int res = 0;
        int R = grid.size();
        int C = grid[0].size();


        for ( int i = 0; i < R; i++) {
            for ( int j = 0; j < C; j++) {
                if ( grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, area);
                    res = max(res, area);

                }
            }
        }

        return res;


    }
};
