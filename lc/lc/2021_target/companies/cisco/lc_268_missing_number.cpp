/*
 * Given an array nums containing n distinct numbers in the range [0, n], return
 * the only number in the range that is missing from the array.
 *
 * Follow up: Could you implement a solution using only O(1) extra space
 * complexity and O(n) runtime complexity?
 *
 *
 *
 *  Example 1:
 *
 *  Input: nums = [3,0,1]
 *  Output: 2
 *  Explanation: n = 3 since there are 3 numbers, so all numbers are in the
 *  range [0,3]. 2 is the missing number in the range since it does not appear
 *  in nums.
 *  Example 2:
 *
 *  Input: nums = [0,1]
 *  Output: 2
 *  Explanation: n = 2 since there are 2 numbers, so all numbers are in the
 *  range [0,2]. 2 is the missing number in the range since it does not appear
 *  in nums.
 *  Example 3:
 *
 *  Input: nums = [9,6,4,2,3,5,7,0,1]
 *  Output: 8
 *  Explanation: n = 9 since there are 9 numbers, so all numbers are in the
 *  range [0,9]. 8 is the missing number in the range since it does not appear
 *  in nums.
 *
*  */

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        if (nums[0] != 0) return 0;
        if ( nums[n-1] != n) return n;

        for (  int i = 1; i < n; i++) {
            if ( nums[i] != i) {
                return i;
            }
        }

        return -1;

    }
};


class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for ( int i = 0; i < nums.size(); i++)
            missing ^= ( i ^nums[i]);

        return missing;

    }
};


int main()
{
    Solution2 sol;
    vector<vector<int>> input = {
        {3,0,1},
        {0,1},
        {9,6,4,2,3,5,7,0,1}
    };

    for ( auto x : input) {
        int r = sol.missingNumber(x);
        cout << "\n Missing number:" << r;
    }

    return 0;
}
