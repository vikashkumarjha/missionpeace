/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:

Each of the array element will not exceed 100.
The array size will not exceed 200.
 

Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].

*/


class Solution {
public:
    
    bool helper(vector<int> &nums, int index , int sum) {
    if ( index >= nums.size()) return false;
    
    if ( sum == nums[index]) return true;
    
    if ( sum < nums[index]) return false;
    
    
    return helper( nums, index + 1, sum ) || helper( nums ,  index + 1, sum - nums[index]);
    
    
}


bool canPartition(vector<int>& nums) {
     if ( nums.empty())
         return false;
     
     int totalSum = accumulate(nums.begin(), nums.end(), 0);
     if ( totalSum % 2)  return false;
     
     totalSum /= 2;
     sort(nums.rbegin(),nums.rend());
     
     return helper(nums, 0, totalSum);
     
 }
    
    
    
   
};
 