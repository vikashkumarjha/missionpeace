/*
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * Example:
 *
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 *     Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *     */

#include "header.hpp"
using namespace std;

int jump(vector<int>& nums) {
    int level = 0;
    int N = nums.size();

    int start = 0;
    int end = 0;
    int maxReachableIndex = INT_MIN;

    while ( end < N - 1) {
        level++;
        for ( int i = start ; i <= end; i++) {
            if ( i + nums[i] >= N - 1) {
                return level;
            }
            maxReachableIndex = max(maxReachableIndex, i + nums[i]);
        }
        start = end + 1;
        end = maxReachableIndex;
    }

    return level;

}


int main() {
    vector<int> nums = {2,3,1,1,4};
    std::cout << "\n Minimum jump required" << jump(nums);
    return 0;

}
