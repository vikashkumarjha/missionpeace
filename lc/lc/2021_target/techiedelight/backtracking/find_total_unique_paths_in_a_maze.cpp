/*: 
 *
 * find total number  unique paths from given source to the given destination...and there are obstacles in the maze so 0 represents obstacle and 1 valid...
 *
 * */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int N = 4;

vector<vector<int>> DIRS = { {-1, 0}, {1, 0}, {0,1}, {0,-1}};

void countPaths(int grid[][N], int isVisited[][N], int x, int y, int &count)
{
  if ( x == N -1 && y == N - 1)
  {
      ++count;
      return;
  }

  isVisited[x][y] = 1;

  if ( grid[x][y] ) {
    for ( auto d : DIRS)
    {
      int x1 = x + d[0];
      int y1 = y + d[1];

      if ( x1 >= 0 && x1 < N && y1 >= 0 && y1 < N && !isVisited[x1][y1])
      {
        countPaths(grid, isVisited, x1, y1, count);
      }
    }
  }

  isVisited[x][y] = 0;


}




int main()
{

  int grid[N][N] = {
    { 1, 1, 1, 1 },
    { 1, 1, 0, 1 },
    { 0, 1, 0, 1 },
    { 1, 1, 1, 1 }

  };

  int count =0;
  int visited[N][N] = {0};
  memset(visited, 0, sizeof(visited));

  countPaths(grid, visited, 0, 0, count);

  cout << "\n The result " << count;
  return 0;
}

