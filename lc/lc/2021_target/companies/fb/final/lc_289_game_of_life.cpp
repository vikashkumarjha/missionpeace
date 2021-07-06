     //live or dead == 1 or 0
        /*
        live to live --> no change
        dead to dead --> no change
        live to dead --> 2
        dead to live --> 3
        10-(origvalue)
        */


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> DIRS = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                int liveNeighbors = 0;
                //get number of liveNeighbors
                for(auto d : DIRS){
                    int i = r + d[0];
                    int j = c + d[1];

                    if (i >= 0 && i < m && j >= 0 && j < n &&
                            (board[i][j] == 1 || board[i][j] == 2))
                        liveNeighbors++;
                }

                if (board[r][c] == 0 && liveNeighbors == 3) {
                    board[r][c] = 3;
                }
                else if (board[r][c] == 1 && (liveNeighbors < 2 || liveNeighbors > 3 )){
                    board[r][c] = 2;
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0;j < n; j++){
                if (board[i][j] == 2) board[i][j] = 0;
                if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};

