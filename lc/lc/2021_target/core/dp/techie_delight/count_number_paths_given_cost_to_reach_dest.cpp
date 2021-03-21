// you can move one unit right or down from any cell
// all cells are positive 
// 



#include "../../header.hpp"










// M x N matrix
#define M 4
#define N 4


int countPath(int m[][N], int r, int c, int cost) {
    if ( cost < 0) return 0;

    if ( r == 0 && c == 0) {

        if ( m[0][0] == cost) {
            return 1;
        }
        return 0; 
    }

    if ( r == 0) {
        countPath(m, r, c-1, cost - m[r][c]);
    }

    if ( c == 0) {
        countPath(m, r-1, c, cost - m[r][c]);
    }

    return countPath(m, r - 1, c, cost - m[r][c]) +
             countPath(m, r, c-1, cost - m[r][c]);
}


 
// create a map to store solutions of subproblems
unordered_map<string, int> lookup;
 
// Recursive top-down function to count total number of paths
// to reach cell (m, n) from cell (0, 0) and having given cost
int countPathsMemo(int mat[][N], int m, int n, int cost)
{
    // base case
    if (cost < 0)
        return 0;
 
    // if we're at first cell (0, 0)
    if (m == 0 && n == 0)
    {
        if (mat[0][0] - cost == 0)
            return 1;
        else
            return 0;
    }
 
    // construct an unique map key from dynamic elements of the input
    string key = to_string(m) + "|" + to_string(n) + "|" + to_string(cost);
 
    // if sub-problem is seen for the first time, solve it and
    // store its result in a map
    if (lookup.find(key) == lookup.end())
    {
        // if we're at first row, we can only go left
        if (m == 0)
            lookup[key] = countPathsMemo(mat, 0, n - 1, cost - mat[m][n]);
 
        // if we're at first column, we can only go up
        else if (n == 0)
            lookup[key] = countPathsMemo(mat, m - 1, 0, cost - mat[m][n]);
 
        // recur to count total paths by going both left and top
        else
            lookup[key] = countPathsMemo(mat, m - 1, n, cost - mat[m][n]) +
                countPathsMemo(mat, m, n - 1, cost - mat[m][n]);
    }
 
    // return total number of paths to reach cell (m, n)
    return lookup[key];
}
 
int main()
{
    int mat[M][N] =
    {
        { 4, 7, 1, 6 },
        { 5, 7, 3, 9 },
        { 3, 2, 1, 2 },
        { 7, 1, 6, 3 }
    };
 
    int cost = 25;
 
    cout << "Total paths with cost " << cost << " are " <<
            countPath(mat, M-1, N-1, cost);


    cout << "Total paths with cost " << cost << " are " <<
            countPathsMemo(mat, M-1, N-1, cost);
 
    return 0;
}




