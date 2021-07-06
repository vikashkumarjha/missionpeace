/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
*/

#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if ( nums.empty()) return 0;
    int res = nums[0];
    int curr = nums[0];

    for ( int i = 1; i < nums.size(); i++)
    {
        curr = max( curr + nums[i], nums[i]);
        res = max(res, curr);
    }
    return res;

}


int main()
{
    vector<int> r = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "\n The result" << maxSubArray(r);
    return 0;

}
