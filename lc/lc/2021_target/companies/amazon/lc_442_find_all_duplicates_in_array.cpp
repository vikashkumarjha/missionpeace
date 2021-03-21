/*Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]

*/

#include "header.hpp"
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for ( int i = 0; i < n; i++) {
            int curr = nums[i];
            int idx = abs(nums[i]) - 1;
            if ( nums[idx] > 0 ) {
                nums[idx] *= -1;
            }else {
                res.push_back(abs(curr));
            }
        }
        return res;
        
        
    }
};