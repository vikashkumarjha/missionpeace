
#include "../../header.hpp"

// this one we should start at top

const int R = 3;
const int C  = 3;

int countPaths(int r, int c) {
    if ( r == R - 1 || c == C -1) {
        return 1;
    }

    return countPaths(r+1, c) + countPaths(r, c+1);

}

int countPathsDP(int m, int n)
{
    // T[i][j] stores the number of paths from cell (0,0) to cell (i,j)
    int T[m][n];
 
    // There is only one way to reach any cell in the first column
    // i.e. to move down
    for (int i = 0; i < m; i++)
        T[i][0] = 1;
 
    // There is only one way to reach any cell in the first row
    // i.e. to move right
    for (int j = 0; j < n; j++)
        T[0][j] = 1;
 
    // fill T[][] in bottom-up manner
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            T[i][j] = T[i-1][j] + T[i][j-1];
        }
    }
 

    // last cell of T[][] stores the count of paths from cell(0,0) to cell(i,j)

    for ( int i = 0; i < m;i++){
        cout << "\n";
        for ( int j = 0; j < n; j++) {
            cout << T[i][j] << " ";
        }
    }


    return T[m-1][n-1];
}



int main()
{
    cout << "\n The number of paths " << countPathsDP(3,3);
}






