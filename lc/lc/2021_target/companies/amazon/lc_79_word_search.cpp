/*

Given an m x n board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells,
 where "adjacent" cells are horizontally or vertically neighboring. 
 The same letter cell may not be used more than once.

*/

#include "header.hpp"

class Solution {
private:
bool dfs(int x, int y, string word, vector<vector<char>> &board) {
    int R = board.size();
    int C = board[0].size();
    if ( (x >= 0 && x < R) && ( y >= 0 && y < C) && word[0] == board[x][y] ) {
        if ( word.size() == 1) {
            return true;
        }
        char ch = board[x][y];
        board[x][y] = '*';
        string tmp = word.substr(1);
        vector<vector<int>> DIRS = { {-1,0}, {1, 0}, {0,1}, {0,-1}};
        for ( int k = 0; k < DIRS.size(); k++) {
            int x1 = x + DIRS[k][0];
            int y1  = y + DIRS[k][1];
            if ( dfs(x1, y1, tmp, board)) {
                return true;
            }
            
        }
        board[x][y] = ch;
     
    }
    return false;
    
}    
public:
    bool exist(vector<vector<char>>& board, string word) {
        if ( board.size() == 0 )
            return false;
        
        int R = board.size();
        int C = board[0].size();
        
        
        for ( int i = 0; i < R; i++) {
            for ( int j = 0; j < C; j++) {
                if ( dfs(i, j, word, board)) {
                    return true;
                } 
                
            }
        }
        return false;
        
        
        
    }
};
class Solution {
public:
    bool doBFS(vector<vector<char>>& board, string &word, int x, int y) {
         queue<pair<pair<int,int>,string>> q;
         
         q.push(make_pair(make_pair(x,y), string(1,word[0])));
         int R = board.size();
         int C = board[0].size();
         vector<vector<bool>> isVisited(R, vector<bool>(C,false));
         isVisited[x][y] = true;
         
        
         vector<vector<int>> DIRS = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        
         while ( !q.empty()) {
            auto qsize = q.size();
           
            while ( qsize--) {
                auto curr = q.front(); q.pop();
                if ( curr.second == word) {
                    return true;
                }
                for ( int k = 0; k < 4; k++) {
                    int x = curr.first.first + DIRS[k][0];
                    int y = curr.first.second + DIRS[k][1];
                    string w = curr.second;
                    
                    if ( x >= 0 && x < R && y >= 0 && y < C && !isVisited[x][y])
                    {
                         if (board[x][y] == word[w.size()]) {
                            
                             q.push(make_pair(make_pair(x,y), w.append(1,board[x][y])));
                             if ( w == word) return true;
                             isVisited[x][y] = true;
                         }
                    }
                    
                }
                
                
            }
            
        }
        return false;
                   
        
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        if ( board.empty()) return false;
        int R = board.size();
        int C = board[0].size();
        
       
        
        for ( int i = 0; i < R; i++) {
            for ( int j = 0; j < C; j++) {
                if ( board[i][j] == word[0]) {
                    if (doBFS(board, word,i, j )) return true;
                   
                }
            }
        }
        
        return false;
        
        
    }
};

