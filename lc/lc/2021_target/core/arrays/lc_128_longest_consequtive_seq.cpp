/*

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Follow up: Could you implement the O(n) solution? 

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9


*/

#include "../../header.hpp"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if ( nums.empty()) return 0;
        unordered_set<int> x(begin(nums), end(nums));
        
        int res = 1;
        
        for ( auto n : nums) {
            int curr = 1;
            if ( x.count(n-1)) {
                int v = n;
                while (x.count(v)) {
                    curr++;
                    v++;
                }
            }
            res = max(res, curr);
        }
        return res;
        
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 0) return 0;
        
        map<int, int>hm;
        for (int i = 0; i < n; i++)
            hm[nums[i]];
        
        auto prev = hm.begin();
        int c = 1, ans = 0;
        
        for (auto it = hm.begin(); it != hm.end(); it++) {
            if (prev->first+1 == it->first) {
                c++;
            } else {
                ans = max(ans, c); c = 1;
            }
            prev = it;
        }
        
        return max(ans, c);
    }
};