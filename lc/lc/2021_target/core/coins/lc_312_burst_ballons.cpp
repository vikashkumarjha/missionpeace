/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167


 */


#include "../header.hpp"



int helper(int l, int r, vector<int> &nums, vector<vector<int>> &dp) {
    if ( l > r) return 0;
    if ( dp[l][r]) return dp[l][r];

    int profit = 0;

    for ( int i = l + 1; i < r; i++) {
        profit = max(profit, nums[l] *nums[i] * nums[r] + helper(l, i, nums, dp) + helper(i, r, nums, dp));
    }

    dp[l][r] = profit;
    return profit;

}



int maxCoins(vector<int> &nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    int n = nums.size();
    vector<vector<int>> dp = vector<vector<int>>(n , vector<int>(n, 0));

    return helper(0, n -1, nums, dp);


}