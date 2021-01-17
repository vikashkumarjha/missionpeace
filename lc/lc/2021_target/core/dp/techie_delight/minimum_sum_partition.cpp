/*

Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 
If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) – sum(Subset2)) should be minimum.
Example: 

Input:  arr[] = {1, 6, 11, 5} 
Output: 1
Explanation:
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11        

*/

#include "header.hpp"
#include <numeric>


int helper(vector<int> &nums, int idx, int s1, int s2) {


    if ( idx < 0) {

        return abs(s1 - s2);
    }

    int exculsive = helper(nums, idx - 1, s1, s2+ nums[idx]);
    int inclusive = helper(nums, idx-1, s1+ nums[idx], s2);

    return min(inclusive, exculsive);

}



// Returns the minimum value of the difference of the two sets.
int findMin(vector<int> &a)
{

    int sum = accumulate(begin(a), end(a), 0);
    int n = a.size();



    // Create an array to store results of subproblems
    vector<vector<int>>  dp(n+1, vector<int>(sum+1));
 
    // Initialize first column as true. 0 sum is possible 
    // with all elements.
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
 
    // Initialize top row, except dp[0][0], as false. With
    // 0 elements, no other sum except 0 is possible
    dp[0][0] = 1;
 
    // Fill the partition table in bottom up manner
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=sum; j++)
        {
            // If i'th element is excluded
            dp[i][j] = dp[i-1][j];
 
            // If i'th element is included
            if (a[i-1] <= j)
                dp[i][j] |= dp[i-1][j-a[i-1]];
        }
    }
  
    // Initialize difference of two sums. 
    int diff = INT_MAX;
     
    // Find the largest j such that dp[n][j]
    // is true where j loops from sum/2 t0 0
    for (int j=sum/2; j>=0; j--)
    {
        // Find the 
        if (dp[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
}



int main()
{
    vector<int> nums = {12,5,16, -12};
    int r = findMin(nums);
    cout << "\n The value is" << r;

}


