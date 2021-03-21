/*
 * Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.

*/

#include "header.hpp"
using namespace std;


bool dfs(vector<vector<char>> &b, int r, int c, string w) {
    if ( !w.size()) return true;
    int R = b.size();
    int C = b[0].size();

     if (r<0 || r>= R || c<0 || c>=C || b[r][c] != w[0])  
        return false;
    char ch = b[r][c];
    b[r][c] = '*';
    string s = w.substr(1);
    bool ret = dfs(b, r-1, c, s) || dfs(b, r+1, c, s) || dfs(b, r, c-1, s) || dfs(b, r, c+1, s);
    b[r][c] = ch;
    return ret;


}


 bool exist(vector<vector<char>>& board, string word) {
     if ( board.empty()) return false;
     int R = board.size();
     int C = board[0].size();

     for ( int i = 0; i < R; i++) {
         for (  int  j = 0; j < C; j++) {
             if ( dfs(board, i, j, word)) {
                 return true;
             }
         }
     }
     return false;
 }

int main() {
    vector<vector<char>> b = {{'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}

    };
    if ( exist(b, "SEEDXX")) {
        std::cout << "\n Exists...";
    }

    return 0;

}
