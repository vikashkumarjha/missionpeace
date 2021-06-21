There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 class Solution {
public:
    
    int bsearch(vector<int> &nums, int l , int r, int key)
    {
        if ( l > r) return -1;
        
        auto m = l + ( r - l) / 2;
        
        if ( nums[m] == key) {
            return m;
        }
        
        if ( nums[l] <= nums[m]) {
            if ( nums[l] <= key && nums[m] >= key) {
                return bsearch(nums, l , r-1, key);
            }
            return bsearch(nums, m+1, r, key);
            
        }else {
            // other half is sorted...
            if ( nums[m] <= key && nums[r] >= key) {
                return bsearch(nums, m+1, r, key);
            }
            return bsearch(nums, l, r-1, key);
            
        }
        
    }
    
    
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return bsearch(nums, 0, nums.size() - 1, target);
        
        
    }
};