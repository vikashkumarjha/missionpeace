/*

Given weights and values of n items, put these items in a knapsack of capacity W to get 
the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] 
and wt[0..n-1] which represent values and weights associated with n items respectively.
 Also given an integer W which represents knapsack capacity, 
 find out the maximum value subset of val[] such that sum of the weights of this subset 
 is smaller than or equal to W. You cannot break an item, 
either pick the complete item or don’t pick it (0-1 property).

*/



#include "../../header.hpp"






int knapsack(int W, int wt[], int val[], int idx)
{
    if ( idx == 0 || W == 0) return 0;

    if ( wt[idx - 1] > W) {
        return knapsack(W, wt, val, idx - 1);
    }

    else {

        return max( val[idx -1] + knapsack(W - wt[idx-1], wt, val, idx-1),
                knapsack(W, wt, val, idx-1));
    }

}

//The top down approach for knapsack with O(nW) runtime and O(nW) space is listed below:

int knapsack(int val[], int wt[], int n, int W)
{
   int dp[n+1][W+1];
   memset(dp, 0, sizeof dp);
   for (int i = 1; i <= n; i++)
   {
       for (w = 1; w <= W; w++)
       {
           dp[i][w] = dp[i-1][w];  //don't include the item
           if (wt[i-1] <= w)
                 dp[i][w] = max(dp[i][w], 
                           val[i-1] + dp[i-1][w-wt[i-1]]);  
       }
   }
   return dp[n][W];
}

//The same knapsack problem could be solved with O(nW) runtime and O(W) space by building the table bottom up as shown below:



int knapsack(int val[], int wt[], int n, int W)
{
    int dp[W+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i < n; i++) 
        for(int j=W; j>=wt[i]; j--)
            dp[j] = max(dp[j] , val[i] + dp[j-wt[i]]);
    return dp[W];
}





  
// Driver code 
int main() 
{ 
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapsack(W, wt, val, n); 
    return 0; 
} 
  