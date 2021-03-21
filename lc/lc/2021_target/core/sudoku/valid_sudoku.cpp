/*

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

*/

#include "../header.hpp"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rowCheck(9, unordered_set<int>());
        vector<unordered_set<int>> colCheck(9, unordered_set<int>());
        vector<unordered_set<int>> boxCheck(9, unordered_set<int>());
        
        
        int R = board.size();
        int C = board[0].size();
        
        for ( int r = 0; r < R; r++){
            for ( int c = 0; c < C; c++) {
                if ( board[r][c] != '.') {
                    int v = board[r][c] - '0' - 1;
                    int boxId = (r/3) * 3 + c/3;
                    if ( rowCheck[r].count(v)) {
                        return false;
                    }
                    if ( colCheck[c].count(v)) {
                        return false;
                    }
                    
                    if ( boxCheck[boxId].count(v)) {
                        return false;
                    }
                    
                    rowCheck[r].insert(v);
                    colCheck[c].insert(v);
                    boxCheck[boxId].insert(v);
                    
                }
                
                
            }
        }
        
        return true;

        
    }
};