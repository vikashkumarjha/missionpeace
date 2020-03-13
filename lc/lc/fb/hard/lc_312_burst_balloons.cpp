/*
 *
 * Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
 * number on it represented by array nums. You are asked to burst all the
 * balloons. If the you burst balloon i you will get nums[left] * nums[i] *
 * nums[right] coins. Here left and right are adjacent indices of i. After the
 * burst, the left and right then becomes adjacent.
 *
 * Find the maximum coins you can collect by bursting the balloons wisely.
 *
 * Note:
 *
 * You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
 * not burst them.
 * 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 *
 * */


#include "header.hpp"
using namespace std;

vector<vector<int>> DP;


int helper( int l, int r, vector<int> &nums) {
    if ( l > r) return 0;
    if ( DP[l][r]) return DP[l][r];

    int maxProfit = 0;

    // valid data set is [l+1, r)

    for ( int i = l + 1; i < r; i++) {
        maxProfit = max(maxProfit, nums[l] * nums[i] * nums[r] + helper(l, i, nums) + helper(i, r, nums));
    }

    DP[l][r] = maxProfit;
    return maxProfit;
}


int maxCoins(vector<int> &nums) {

    // add 1 to the both sides so we can burst them.
    nums.insert(nums.begin() , 1);
    nums.push_back(1);

    int N = nums.size();
    DP = vector(N, vector<int>(N, 0));
    return helper(0, N - 1, nums);


}


int main() {
    vector<int> nums = {3,1,5,8};
    std::cout << "\n Maximum points" << maxCoins(nums);

}
