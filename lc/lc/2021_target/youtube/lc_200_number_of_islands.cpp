#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    vector<pair<int,int>> DIRS = { {-1,0}, {1,0}, {0,1}, {0,-1}};
public:
    void dfs(int r, int c, int R, int C, vector<vector<char>> &g) {
        g[r][c] = '0';
        for ( auto dir : DIRS) {
            int nr = dir.first + r;
            int nc = dir.second + c;

            if ( nr >= 0 && nr < R && nc >= 0 && nc < C ){
                if ( g[nr][nc] == '1') {
                    dfs(nr, nc, R, C, g);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        if ( R == 0) return 0;
        int C = grid[0].size();
        int result = 0;

        for ( int r = 0; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                if ( grid[r][c] == '1') {
                    result++;
                    dfs(r, c, R, C, grid);
                }
            }
        }
        return result;
    }
};

class SolutionBFS {
private:
        vector<pair<int,int>> DIRS = { {-1,0}, {1,0}, {0,1}, {0,-1}};
public:
    void bfs(int r, int c, int R, int C, vector<vector<char>> &g) {
        queue<pair<int,int>> q;
        q.push(make_pair(r,c));
        while (!q.empty()) {
            auto curr = q.front(); q.pop();
            int x = curr.first;
            int y = curr.second;
            g[x][y] = '0';
            for ( auto dir : DIRS ) {
                int nx = dir.first + x;
                int ny = dir.second + y;
                if ( nx >= 0 && nx < R && ny >=0 && ny < C) {
                    if ( g[nx][ny] == '1') {
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int R = grid.size();
        if ( R == 0) return 0;
        int C = grid[0].size();
        int result = 0;

        for ( int r = 0; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                if ( grid[r][c] == '1') {
                    result++;
                    bfs(r, c, R, C, grid);
                }
            }
        }
        return result;
    }
};




int main()
{
    vector<vector<char>> g = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    SolutionBFS s;
    int r = s.numIslands(g);
    cout << "\n The value of the result:" << r;
    return 0;

}
