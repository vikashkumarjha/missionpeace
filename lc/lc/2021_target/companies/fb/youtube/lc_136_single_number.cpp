#if 0
#include "header.hpp"
using namespace std;


// https://leetcode.com/problems/single-number/

/*
 * Given a non-empty array of integers, every element appears twice except for
 * one. Find that single one.
 *
 * Note:
 *
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 *
 * Example 1:
 *
 * Input: [2,2,1]
 * Output: 1
 * Example 2:
 *
 * Input: [4,1,2,1,2]
 * Output: 4
 *
 * */

int singleNumber(vector<int>& nums) {
    int res = 0;
    for ( auto n : nums ) {
        res ^= n;
    }
    return res;
}

int main() {
    vector<int> nums = {1,2,1,2, 3,5,3};
    std::cout << "\n The number" << singleNumber(nums);
    return 0;
}

#endif
