class Solution {
public:
    void bfs(int r, int c , vector<vector<char>> &b) {
        queue<pair<int,int>> q;
        q.push(make_pair(r,c));

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int x = p.first;
            int y = p.second;

            b[x][y] = '#';


            vector<vector<int>> DIRS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};;
            for ( auto d : DIRS) {
                int nx = x + d[0];
                int ny = y + d[1];
                if ( nx >= 0 && nx < b.size() && ny >= 0 && ny < b[0].size()) {
                    if ( b[nx][ny] == 'O') {
                        b[nx][ny] = '#';
                        q.push(make_pair(nx,ny));
                    }

                } 
            }
        }

    }


    void solve(vector<vector<char>>& board) {
        int R = board.size();
        if ( R == 0) return;
        int C = board[0].size();

        for ( int r = 0; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                if ( r == 0 || r == R-1 || c == C-1 || c == 0) {
                    if ( board[r][c] == 'O') {

                        bfs(r,c, board);
                    }
                }

            }
        }


        for ( int r = 0; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                if ( board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                if ( board[r][c] == '#') {
                    board[r][c] = 'O';
                }

            }
        }




    }
};
