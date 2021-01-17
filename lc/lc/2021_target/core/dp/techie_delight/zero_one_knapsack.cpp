/*




*/




#include "header.hpp"

int knapsack(int wt[], int val[], int n, int W) {
    if ( W < 0) {
        return INT_MIN;
    }

    // if no item left or capacity is zero
    if ( n < 0 || W == 0) {
        return 0;
    }

    int inclusive= val[n] + knapsack(wt, val, n-1, W - wt[n]);
    int exclusive= knapsack(wt, val, n-1, W);

    return max(inclusive, exclusive);
}





// create a map to store solutions of subproblems
unordered_map<string, int> lookup;
 
// Values (stored in array v)
// Weights (stored in array w)
// Number of distinct items (n)
// Knapsack capacity W
int knapSackMemo(int v[], int w[], int n, int W)
{
    // base case: Negative capacity
    if (W < 0)
        return INT_MIN;
 
    // base case: no items left or capacity becomes 0
    if (n < 0 || W == 0)
        return 0;
 
    // construct an unique map key from dynamic elements of the input
    string key = to_string(n) + "|" + to_string(W);
 
    // if sub-problem is seen for the first time, solve it and
    // store its result in a map
    if (lookup.find(key) == lookup.end())
    {
        // Case 1. include current item n in knapSack (v[n]) & recur for
        // remaining items (n - 1) with decreased capacity (W - w[n])
        int include = v[n] + knapSackMemo(v, w, n - 1, W - w[n]);
 
        // Case 2. exclude current item n from knapSack and recur for
        // remaining items (n - 1)
        int exclude = knapSackMemo(v, w, n - 1, W);
 
        // assign max value we get by including or excluding current item
        lookup[key] = max (include, exclude);
    }
 
    // return solution to current sub-problem
    return lookup[key];
}
// Input:
// Values (stored in array v)
// Weights (stored in array w)
// Number of distinct items (n)
// Knapsack capacity W
int knapSackDP(int v[], int w[], int n, int W)
{
    // T[i][j] stores the maximum value that can be attained with
    // weight less than or equal to j using items up to first i items
    int T[n+1][W+1];
 
    for (int j = 0; j <= W; j++)
        T[0][j] = 0;
 
    // memset (T[0], 0, sizeof T[0]);
 
    // do for ith item
    for (int i = 1; i <= n; i++)
    {
        // consider all weights from 0 to maximum capacity W
        for (int j = 0; j <= W; j++)
        {
            // don't include ith element if j-w[i-1] is negative
            if (w[i-1] > j)
                T[i][j] = T[i-1][j];
            else
            // find max value by excluding or including the ith item
                T[i][j] = max(T[i-1][j],
                            T[i-1][j-w[i-1]] + v[i-1]);
        }
    }
 
    // return maximum value
    return T[n][W];
}


int main()
{
    int wt[] = {1,2,3,8,7,4};
    int val[] = {20,5,10,40,15,25};

    // knapsack capacity
    int W = 10;

    int n = sizeof(val)/sizeof(val[0]);


    cout << "\n The knapsack value" << knapsack(wt, val, n-1, W);





}

