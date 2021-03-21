//Given a set of positive numbers and an integeer s
// is there any empty subset whose sum is s


#include "header.hpp"


bool helper(vector<int> &a, int idx, int sum) {
    if ( sum == 0) {
        return true;
    }
   
    if ( idx < 0 || sum < 0) {
        return 0;
    }

    bool exclude = helper(a, idx-1, sum);
    bool include = helper(a, idx-1, sum - a[idx]);

    return include || exclude;


}





bool isSubsetSum(vector<int> &a, int sum) {

    int n = a.size();
    return helper(a, n-1, sum );



} 


#include <iostream>
using namespace std;
 
// Return true if there exists a subsequence of arr[0..n) with given sum
bool subsetSum(int arr[], int n, int sum)
{
    // T[i][j] stores true if subset with sum j can be attained with
    // using items up to first i items
    bool T[n + 1][sum + 1];
 
    // if 0 items in the list and sum is non-zero
    for (int j = 1; j <= sum; j++)
        T[0][j] = false;
 
    // if sum is zero
    for (int i = 0; i <= n; i++)
        T[i][0] = true;
 
    // do for ith item
    for (int i = 1; i <= n; i++)
    {
        // consider all sum from 1 to sum
        for (int j = 1; j <= sum; j++)
        {
            // don't include ith element if j-arr[i-1] is negative
            if (arr[i - 1] > j)
                T[i][j] = T[i - 1][j];
            else
            // find subset with sum j by excluding or including the ith item
                T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
        }
    }
 
    // return maximum value
    return T[n][sum];
}
 
// Subset Sum Problem
int main()
{
    // Input: set of items and a sum
    int arr[] = { 7, 3, 2, 5, 8 };
    int sum = 18;
 
    // number of items
    int n = sizeof(arr) / sizeof(arr[0]);
 
    if (subsetSum(arr, n, sum))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}







// create a map to store solutions of subproblems
unordered_map<string, bool> lookup;
 
// Return true if there exists a subsequence of arr[0..n] with given sum
bool subsetSum(int arr[], int n, int sum)
{
    // return true if sum becomes 0 (subset found)
    if (sum == 0)
        return true;
 
    // base case: no items left or sum becomes negative
    if (n < 0 || sum < 0)
        return false;
 
    // construct an unique map key from dynamic elements of the input
    string key = to_string(n) + "|" + to_string(sum);
 
    // if sub-problem is seen for the first time, solve it and
    // store its result in a map
    if (lookup.find(key) == lookup.end())
    {
        // Case 1. include current item in the subset (arr[n]) and recur
        // for remaining items (n - 1) with remaining sum (sum - arr[n])
        bool include = subsetSum(arr, n - 1, sum - arr[n]);
 
        // Case 2. exclude current item n from subset and recur for
        // remaining items (n - 1)
        bool exclude = subsetSum(arr, n - 1, sum);
 
        // assign true if we can get subset by including or excluding the
        // current item
        lookup[key] = include || exclude;
    }
 
    // return solution to current sub-problem
    return lookup[key];
}
 


int main()
{
    vector<int> a = { 7, 3, 2, 5, 8};
    if ( isSubsetSum(a, 100)) {
        cout << "\n exists...";
    }else {
        cout << "\n does not...";
    }

}
