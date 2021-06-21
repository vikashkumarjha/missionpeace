#include <iostream>
#include <vector>

using namespace std;
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

int main()
{
    vector<int> arr = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int l = 0;
    int r = arr.size() - 1;

    int key = 6;
    int idx = search(arr, l, r, key);
    if ( idx != -1) {
        cout << "\n Found the key at index:" << idx;
    }else {
        cout << "\n Found the key at index:" << idx;
    }
    return 0;

}

