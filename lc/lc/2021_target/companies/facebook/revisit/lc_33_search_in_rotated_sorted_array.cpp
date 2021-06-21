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