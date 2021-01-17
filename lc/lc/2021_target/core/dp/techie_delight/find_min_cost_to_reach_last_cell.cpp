// cost to reach cell ( i , j) = cost[i][j] + min((cost to reach i-1, j), (cost to reach i, j-1))

#include "header.hpp"



int findMinCost(vector<vector<int>> &g, int r, int c) {
    if ( r == 0 || c == 0) {
        return INT_MAX;
    }

    if (r == 1 && c == 1) {
        return g[0][0];
    }

    return min(findMinCost(g, r-1, c) , findMinCost(g, r, c-1)) + g[r-1][c-1];
}



int findMinCostDP(vector<vector<int>> &g) {
    int R = g.size();
    int C = g[0].size();

    vector<vector<int>> dp(R, vector<int>(C,0));

    dp[0][0] = g[0][0];

    //fill the first row
    for ( int c = 1; c < C; c++) {
        dp[0][c] = g[0][c];
        dp[0][c] += dp[0][c-1];
    }


    // fill the first col
     for ( int r = 1; r < R; r++) {
        dp[r][0] = g[r][0];
        dp[r][0] += dp[r-1][0];
    }

    for ( int r = 1; r < R; r++) {
        for ( int c = 1; c < C; c++) {
            dp[r][c] = g[r][c];
            dp[r][c] += min(dp[r-1][c], dp[r][c-1]) ;
        }
    }

    return dp[R-1][C-1];

}




int main()
{

    vector<vector<int>> grid = {

        {4, 7, 8, 6, 4},
        {6, 7, 3, 9, 2},
        {3, 8, 1, 2, 4},
        {7, 1, 7, 3, 7},
        {2, 9, 8, 9, 3}
    };
    int R = grid.size();

    int C = grid[0].size();


    int res = findMinCost(grid, R, C);
    int res2 = findMinCostDP(grid);

    cout << "\n THe minimum cost:" << res;
    cout << "\n THe minimum cost:" << res2;
    return 0;


}