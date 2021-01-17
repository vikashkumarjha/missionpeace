
#include "../header.hpp"
int maxSumSubseq(int arr[], int i, int n, int prev)
{
    // base case: all elements are processed
    if (i == n)
        return 0;
 
    // recur by excluding current element
    int excl = maxSumSubseq(arr, i + 1, n, prev);
 
    int incl = 0;
 
    // include current element only if it is not adjacent
    // to previous element considered
    if (prev + 1 != i)
        incl = maxSumSubseq(arr, i + 1, n, i) + arr[i];
 
    // return maximum sum we get by including or excluding
    // current item
    return max(incl, excl);
}
 
int main_rec()
{
    int arr[] = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Maximum sum is " << maxSumSubseq(arr, 0, n, INT_MIN);
 
    return 0;
}


// DP solution to calculate maximum sum in the given array with
// no adjacent elements considered (Function uses extra space)
int maxSumSubseq(int arr[], int n)
{
    // base case
    if (n == 1)
        return arr[0];
 
    // create an auxiliary array to store solution of sub-problems
    int lookup[n];
 
    // lookup[i] stores the maximum sum possible till index i
 
    // trivial case
    lookup[0] = arr[0];
    lookup[1] = max(arr[0], arr[1]);
 
    // traverse array from index 2
    for (int i = 2; i < n; i++)
    {
        // lookup[i] stores the maximum sum we get by
 
        // 1. excluding current element & take maximum sum till index i-1
        // 2. including current element arr[i] and take maximum sum
        //    till index i-2
        lookup[i] = max(lookup[i-1], lookup[i-2] + arr[i]);
 
        // if current element is more than max sum till current element
        lookup[i] = max(lookup[i], arr[i]);
    }
 
    // return maximum sum
    return lookup[n-1];
}