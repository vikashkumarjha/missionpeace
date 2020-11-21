//
//  lc_200_number_of_islands.cpp
//  lc
//
//  Created by vikash kumar jha on 3/7/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.


//


/*
 Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 Example 1:

 Input:
 11110
 11010
 11000
 00000

 Output: 1
 Example 2:

 Input:
 11000
 11000
 00100
 00011

 Output: 3
 */


#if 0



#include "header.hpp"

using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j) {
    
    int R = grid.size();
    int C = grid[0].size();
    
    vector<vector<int>> DIRS = { {1,0}, {0,1}, {-1,0}, {0,-1}};
    
    grid[i][j] = '0';
    
    
    for ( int k = 0; k < DIRS.size(); k++) {
        int x = i + DIRS[k][0];
        int y = j + DIRS[k][1];
        
        if ( x >= 0 && x < R && y >= 0 && y < C && grid[x][y] == '1') {
            dfs(grid, x, y);
        }
        
    }
    
}



int numIslands(vector<vector<char>> &grid) {
    if ( grid.empty()) return 0;
    int R = grid.size();
    int C = grid[0].size();
    
    int numOfIslands = 0;
    for ( int i = 0; i < R; i++) {
        for ( int j = 0; j < C; j++) {
            if ( grid[i][j] == '1') {
                ++numOfIslands;
                dfs(grid, i, j);
                
            }
        }
    }
    
    
    return numOfIslands;
    
}


class Solution {

private:

public:
    

    
bool isSafe(std::vector<vector<char>> &grid, int x, int M,  int y, int N, std::vector<std::vector<bool>> &isVisited)
{
    return (x >= 0) && (x < M) && (y >= 0) && (y < N) &&
        (grid[x][y] == '1' && !isVisited[x][y]);
}
void bfs(std::vector<vector<char>>& grid, std::vector<std::vector<bool>> &isVisited, int row , int col)
{
        int nr = grid.size();
        int nc = grid[0].size();
        std::queue<std::pair<int,int>> q;
        q.push(std::make_pair(row,col));
       int row_move[] = { -1, 0, 0, 1 };
        int col_move[] = { 0, -1, 1, 0 };
    
        //mark is processed
        isVisited[row][col] = true;
        while ( !q.empty())
        {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
            
               for (int k = 0; k < 4; k++)
               {
                // skip if location is invalid or it is already
               // processed or consists of water
                  if (isSafe(grid, x + row_move[k], nr, y + col_move[k], nc, isVisited))
                 {
                  // mark it processed & push it into the queue
                   isVisited[x + row_move[k]][y + col_move[k]] = 1;
                   q.push(make_pair(x + row_move[k], y + col_move[k]));
                 }
                }
            
        }


}
    
int numIslands(vector<vector<char>>& grid)
{
        if ( grid.empty()) return 0;

         int nr = grid.size();
        int nc = grid[0].size();

        std::vector<std::vector<bool>> isVisited(nr,std::vector<bool>(nc,false));

        int result = 0;

        for ( int i = 0; i < nr; i++)
        {
                for ( int j = 0; j < nc; j++)
                {
                        if ( grid[i][j] == '1' && isVisited[i][j] == false)
                        {
                                bfs(grid, isVisited, i, j);
                                ++result;
                        }
                }
        }

        return result;
}
};


int main() {
    std::cout << "\n in the main....";
    return 0;
}

#endif
