/*

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

*/


      //live or dead == 1 or 0
        /*
        live to live --> no change
        dead to dead --> no change
        live to dead --> 2
        dead to live --> 3
        10-(origvalue)
        */



#include "header.hpp"

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
