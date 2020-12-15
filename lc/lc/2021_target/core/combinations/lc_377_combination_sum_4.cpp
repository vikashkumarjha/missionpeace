/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> waysDP(target + 1, 0);
        waysDP[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int x : nums) {
                if (i >= x) 
                    waysDP[i] = waysDP[i] + waysDP[i - x];
            }
        }
        
        return waysDP[target];
    }
};