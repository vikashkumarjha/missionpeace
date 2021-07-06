/*
 * Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

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


/*
 * Time Complexity: \mathcal{O}(N \cdot 3 ^ L)O(N⋅3
L
 ) where NN is the number of cells in the board and LL is the length of the word to be matched.

For the backtracking function, initially we could have at most 4 directions to explore, but further the choices are reduced into 3 (since we won't go back to where we come from). As a result, the execution trace after the first step could be visualized as a 3-ary tree, each of the branches represent a potential exploration in the corresponding direction. Therefore, in the worst case, the total number of invocation would be the number of nodes in a full 3-nary tree, which is about 3^L3
L
 .

We iterate through the board for backtracking, i.e. there could be NN times invocation for the backtracking function in the worst case.

As a result, overall the time complexity of the algorithm would be \mathcal{O}(N \cdot 3 ^ L)O(N⋅3
L
 ).

 */
