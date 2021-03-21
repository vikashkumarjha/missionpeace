#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;



const int N = 8;




void printSolution(char b[][N])
{
  cout << "\n";

  for ( int r = 0; r < N; r++){
    cout << "\n";
    for ( int c = 0; c < N; c++)
      cout << b[r][c] << "  ";
  }
}

// Function to check if two queens threaten each other or not
int isSafe(char mat[][N], int r, int c)
{
	// return 0 if two queens share the same column
	for (int i = 0; i < r; i++)
	{
		if (mat[i][c] == 'Q') {
			return 0;
		}
	}

	// return 0 if two queens share the same `` diagonal
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
	{
		if (mat[i][j] == 'Q') {
			return 0;
		}
	}

	// return 0 if two queens share the same `/` diagonal
	for (int i = r, j = c; i >= 0 && j < N; i--, j++)
	{
		if (mat[i][j] == 'Q') {
			return 0;
		}
	}

	return 1;
}



void solveNQueens(char b[][N], int row)
{

  if ( row == N )
  {
      printSolution(b);
      return;
  }

  for ( int c = 0; c < N; c++)
  {
    if (isSafe(b, row, c))
    {
        b[row][c] = 'Q';
        solveNQueens(b, row+1);
        b[row][c] = '*';

    }


  }


}

int main()
{

  cout << "the value of " << N;


  char board[N][N];
  memset(board,'*', sizeof(board));

  solveNQueens(board, 0);

  return 0;
}
