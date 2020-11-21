/*
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 *
 * */

#include "header.hpp"
using namespace std;




int threeSumClosest(vector<int>& nums, int target) {
    int closetVal = INT_MAX;
    sort(nums.begin(), nums.end());
    int N = nums.size() ;

    for ( int i = 0; i < N - 2; i++) {
        int curr = nums[i];
        int l = i+1;
        int r = N - 1;
        while ( l < r) {
            int currSum = nums[i] + nums[l] + nums[r];
            closetVal = min(closetVal,  abs(currSum - target));
            if ( currSum > target) {
                r--;
            }else {
                l++;
            }
        }
    }
    return closetVal;
}
