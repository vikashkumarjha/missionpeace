/*
 * Given a binary matrix , find the longest possible route from the source to the destination by moving to only non-zero ajacent position. NO cycles */

#include<iostream>
#include<cstring>
#include<string>
#include<vector>


using namespace std;


const int R = 10;
const int C = 10;


vector<vector<int>> DIRS = {
    {-1,0},
    {1,0},
    {0,1},
    {0,-1}
};






void findLongestPath(int b[R][C], int isVisited[R][C], int r, int c, int destX, int destY, int &res, int dist)
{

    if ( b[r][c] == 0)
      return;

    if (r == destX && c == destY)
    {
      res = max(res, dist);
      return;
    }

    isVisited[r][c] = 1;

    for ( auto d : DIRS)
    {
      int x = r + d[0];
      int y = c + d[1];

      if ( x >= 0 && x < R && y >= 0 && y < C)
      {
        if ( isVisited[x][y] == 0)
        {
          findLongestPath(b, isVisited, x, y, destX, destY, res, dist + 1);
        }
    
      }
    }

    isVisited[r][c]= 0;
}


int main()
{

  int mat[R][C] = {

    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
    { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
    { 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 1, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 0, 0, 1, 1 },
    { 1, 1, 0, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }

  };


  int  isVisited[R][C] ;
  memset(isVisited, 0, sizeof(isVisited));

  int res = 0;

  findLongestPath(mat, isVisited, 0, 0, 5, 7, res, 0);

  cout << "\n The longest path: " << res;

  


}












