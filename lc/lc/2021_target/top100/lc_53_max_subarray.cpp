#include "../header.hpp"

/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

*/



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if ( nums.empty()) return INT_MIN;
        int currSum = nums[0];
        int maxSum = nums[0];
        int n = nums.size();

        for ( int i = 1; i < n; i++) {
            //either include or exclude
            currSum = max(nums[i], nums[i] + currSum);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }

    int maxSubArray2(vector<int> &nums) {
        int maxSoFar = INT_MIN;
        int maxEndingHere = 0;

        for ( int i = 0; i < nums.size(); i++) {
            maxEndingHere += nums[i];
            if ( maxEndingHere > maxSoFar) 
                maxSoFar = maxEndingHere;

            if ( maxEndingHere < 0) {
                maxEndingHere = 0;
            }    
        }
        return maxSoFar;

    }
};

/*
maxSubArray for array with n numbers:

If n == 1 : return this single element.

left_sum = maxSubArray for the left subarray, i.e. for the first n/2 numbers (middle element at index (left + right) / 2 always belongs to the left subarray).

right_sum = maxSubArray for the right subarray, i.e. for the last n/2 numbers.

cross_sum = maximum sum of the subarray containing elements from both left and right subarrays and hence crossing the middle element at index (left + right) / 2.

Merge the subproblems solutions, i.e. return max(left_sum, right_sum, cross_sum).

*/

class Solution2 {
public:
    int cross(vector<int> &nums, int left, int right, int m) {
        if (left == right) return nums[left];
        int leftSubSum = -10000;
        int currSum = 0;
        for ( int i = m; i > left - 1; i--){
            currSum += nums[i];
            leftSubSum = max(leftSubSum, currSum);
        }
        
        int rightSubSum = -10000;
        currSum = 0;
        for ( int i = m+1; i < right + 1; i++){
            currSum += nums[i];
            rightSubSum = max(rightSubSum, currSum);
        }
        return leftSubSum + rightSubSum;
        
    }
    int helper(vector<int> &nums, int left, int right) {
            if ( left == right) return nums[left];
            int m = (left +  right)/2;
            int leftSum = helper(nums, left, m);
            int rightSum = helper(nums, m + 1, right);
            int crossSum = cross(nums, left, right, m);
            return max(max(leftSum, rightSum), crossSum);
        
        
    }
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n - 1);
        
    }
};





int main()
{
    vector<int> n = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    int r = s.maxSubArray(n);
    std::cout << "\n Result:" << r;
}







