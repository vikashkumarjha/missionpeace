/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
 An island is surrounded by water and is formed by connecting adjacent lands horizontally or 
 vertically. 
You may assume all four edges of the grid are all surrounded by water. */

#include <iostream>
#include <unordered_map>
#include <vector>
#include<queue>

using namespace std;

class Solution {
 private:
    vector<vector<int>> DIRS = { {0,1}, {0,-1}, {-1,0}, {1,0}}; 
    void dfs(int r, int c, vector<vector<char>> &g) {
        g[r][c] = '0';
        int nr = g.size();
        int nc = g[0].size();

        for ( int k = 0; k < DIRS.size(); k++) {
            int row = r + DIRS[k][0];
            int col = c + DIRS[k][1];

            if( (row >= 0 && row < nr) && (col >= 0 && col < nc) ){
                    if ( g[row][col] == '1') 
                        dfs(row,col, g);
            }
        }
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        int nr,nc;
        nr = grid.size();
        nc = (nr == 0 ) ? 0 : grid[0].size();
        int result = 0;

        for ( int r = 0; r < nr; r++) {
            for ( int c = 0; c < nc; c++) {
                if (grid[r][c] == '1') {
                    result++;
                    dfs(r,c, grid);
                }
            }
        }
        return result;
        
    }
};

class Solution2
{

private:
public:
    bool isSafe(std::vector<vector<char>> &grid, int x, int M, int y, int N, std::vector<std::vector<bool>> &isVisited)
    {
        return (x >= 0) && (x < M) && (y >= 0) && (y < N) &&
               (grid[x][y] == '1' && !isVisited[x][y]);
    }
    void bfs(std::vector<vector<char>> &grid, std::vector<std::vector<bool>> &isVisited, int row, int col)
    {
        int nr = grid.size();
        int nc = grid[0].size();
        std::queue<std::pair<int, int>> q;
        q.push(std::make_pair(row, col));
        int row_move[] = {-1, 0, 0, 1};
        int col_move[] = {0, -1, 1, 0};

        //mark is processed
        isVisited[row][col] = true;
        while (!q.empty())
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

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int nr = grid.size();
        int nc = grid[0].size();

        std::vector<std::vector<bool>> isVisited(nr, std::vector<bool>(nc, false));

        int result = 0;

        for (int i = 0; i < nr; i++)
        {
            for (int j = 0; j < nc; j++)
            {
                if (grid[i][j] == '1' && isVisited[i][j] == false)
                {
                    bfs(grid, isVisited, i, j);
                    ++result;
                }
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    Solution s;
   // int x =s.numIslands(grid);
   // std::cout << "\n Number of islands:" << x;

    Solution2 s2;
    int x =s2.numIslands(grid);
    std::cout << "\n Number of islands:" << x;
    return 0;
}
