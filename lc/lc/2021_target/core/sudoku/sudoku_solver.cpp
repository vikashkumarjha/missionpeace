/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

*/

#include "../header.hpp"

class Solution {
public:
    bool check(vector<vector<char>> &board, int i, int j, char val)
    {
        for(int x=0; x<9; x++) if(board[x][j] == val) return false;
        for(int y=0; y<9; y++) if(board[i][y] == val) return false;

        // TOP LEFT ORIGIN
        int subBoxX = i - i%3, subBoxY = j - j%3;
        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                if(board[subBoxX+x][subBoxY+y] == val) return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>> &board, int i, int j)
    {
        if(i==9) return true;
        if(j==9) return helper(board, i+1, 0);
        if(board[i][j] != '.') return helper(board, i, j+1);

        for(char c='1'; c<='9'; c++)
        {
            if(check(board, i, j, c))
            {
                board[i][j] = c;
                if(helper(board, i, j+1)) return true;
                board[i][j] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);

    }
};
