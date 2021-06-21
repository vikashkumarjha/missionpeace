class Solution {
public:
    vector<vector<string>> solveNQueens(const int& n) {
        vector<vector<string>> result;
        
        vector<string> board(n, string(n, '.'));
        solveNQueens(result, board, 0, n);
        return result;
    }
private:
    void solveNQueens(vector<vector<string>>& res, vector<string>& board, const int& row, const int& R) {
        if (row == R) {
            res.push_back(board);
            return;
        }
        else {
            for (int i = 0; i < R; ++i) {
                if (isValid(row, i, board, R)) {
                    board[row][i] = 'Q';
                    solveNQueens(res, board, row + 1, R);
                    board[row][i] = '.';
                }
            }
            return;
        }
    }
private:
    bool isValid(const int& row, const int& column, const vector<string>& solution, const int& R) {
        
        // for the row check the coll
        for (int i = 0; i < row; ++i) {
            if (solution[i][column] == 'Q')
                return false;
        }
        // diagonal
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; --i, --j) {
            if (solution[i][j] == 'Q')
                return false;
        }
        //anti diagonal
        for (int i = row - 1, j = column + 1; i >= 0 && j <= R - 1; --i, ++j) {
            if (solution[i][j] == 'Q')
                return false;
        }
        return true;
    }
};
