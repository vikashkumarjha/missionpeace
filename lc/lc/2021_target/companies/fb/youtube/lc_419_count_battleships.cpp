/*
 * Given an 2D board, count how many battleships are in it. The battleships are
 * represented with 'X's, empty slots are represented with '.'s. You may assume
 * the following rules:
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words,
 * they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1
 * column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships -
 * there are no adjacent battleships.
 * Example:
 * X..X
 * ...X
 * ...X
 *
 * In the above board there are 2 battleships.
 * */

class Solution {
public:
    int m, n;
    vector<vector<bool>> isVisited;
    int DIRS[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.' || isVisited[i][j]) return;
        isVisited[i][j] = true;
        for (int d = 0; d < 4; ++d)
            dfs(board, i+DIRS[d][0], j+DIRS[d][1]);
    }

    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        m = board.size(), n = board[0].size();
        isVisited.resize(m, vector<bool>(n, false));
        int result = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (board[i][j] == 'X' && !isVisited[i][j]) {
                    ++result;
                    dfs(board, i, j);
                }
        return result;
    }
};

////Only count the Xs whose left and up neighbors are both ..
class Solution2 {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0, battleships = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    if ((!i || board[i - 1][j] == '.') && (!j || board[i][j - 1] == '.')) {
                        battleships++;
                    }
                }
            }
        }
        return battleships;
    }
};
