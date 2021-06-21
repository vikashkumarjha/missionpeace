/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        if ( nums.size() < 2) return nums.size();
        int res = 1;
        sort(begin(nums), end(nums));
        int n = nums.size();
        int curr = 1;
        for ( int i = 1; i < n; i++) {
            if ( nums[i] == nums[i-1] + 1) {
                curr += 1; 
            }else {
                res = max(res, curr);
                curr = 1;
            }
            
        }
        return max(res, curr);
        
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if ( nums.size() < 2) return nums.size();
        unordered_set<int> data(begin(nums), end(nums));
        int res = 1;
        for ( int i = 1; i < nums.size();i++) {
            if ( data.count(nums[i] - 1)) {
                int x = nums[i];
                while ( data.count(x)) {
                    x++;
                }
                res = max(res, x - nums[i] + 1);
            }
        }
        return res;
        
        
    }
};