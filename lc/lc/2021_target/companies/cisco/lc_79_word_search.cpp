/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Note: There will be some test cases with a board or a word larger than constraints to test if your solution is using pruning
*/


class Solution {

    bool visited[256][256];

    bool existUtil(vector<vector<char>>& board, string& word, int k, int i, int j, int m, int n) {

        if (k == word.length()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (visited[i][j]) return false;
        if (word[k] != board[i][j]) return false;

        visited[i][j] = true;
        bool ret = existUtil(board, word, k+1, i-1, j, m, n) || existUtil(board, word, k+1, i, j+1, m, n)
            || existUtil(board, word, k+1, i+1, j, m, n) || existUtil(board, word, k+1, i, j-1, m, n);
        visited[i][j] = false;

        return ret;
    }

public:

    bool exist(vector<vector<char>>& board, string word) {

        if (board.empty()) return false;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && existUtil(board, word, 0, i, j, m, n))
                    return true;
            }
        }

        return false;
    }
};
