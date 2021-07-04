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

            if ( x >= 0 && x < R && y > = 0 && y < C) {
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


class Solution {
private:
public:
    bool isSafe(std::vector<vector<char>> &grid, int x, int M,  int y, int N, std::vector<std::vector<bool>> &isVisited)
    {
        return (x >= 0) && (x < M) && (y >= 0) && (y < N) &&
            (grid[x][y] == '1' && !isVisited[x][y]);
    }
    void bfs(std::vector<vector<char>>& grid, std::vector<std::vector<bool>> &isVisited, int row , int col)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        std::queue<std::pair<int,int>> q;
        q.push(std::make_pair(row,col));
        int row_move[] = { -1, 0, 0, 1 };
        int col_move[] = { 0, -1, 1, 0 };
        //mark is processed
        isVisited[row][col] = true;
        while ( !q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                // skip if location is invalid or it is already
                // processed or consists of water
                if (isSafe(grid, x + row_move[k], nr, y + col_move[k], nc, isVisited))
                {
                    // mark it processed & push it into the queue
                    isVisited[x + row_move[k]][y + col_move[k]] = 1;
                    q.push(make_pair(x + row_move[k], y + col_move[k]));
                }
            }

        }


    }

    int numIslands(vector<vector<char>>& grid)
    {
        if ( grid.empty()) return 0;

        int nr = grid.size();
        int nc = grid[0].size();

        std::vector<std::vector<bool>> isVisited(nr,std::vector<bool>(nc,false));

        int result = 0;

        for ( int i = 0; i < nr; i++)
        {
            for ( int j = 0; j < nc; j++)
            {
                if ( grid[i][j] == '1' && isVisited[i][j] == false)
                {
                    bfs(grid, isVisited, i, j);
                    ++result;
                }
            }
        }

        return result;
    }
};
