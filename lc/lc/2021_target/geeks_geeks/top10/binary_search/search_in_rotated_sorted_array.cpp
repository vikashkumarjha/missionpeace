#include <iostream>
#include <vector>


using namespace std;
class Solution
{
public:
    int helper(vector<int> &a, int l, int r, int key)
    {
        if (l > r)
            return -1;

        auto m = l + (r - l) / 2;

        if (a[m] == key)
            return m;

        if (a[l] <= a[m])
        {
            // l to m is sorted
            if (key >= a[l] && key <= a[m])
            {
                return helper(a, l, m - 1, key);
            }

            return helper(a, m + 1, r, key);
        }
        else
        {
            // m , r must be sorted
            if (key >= a[m] && key <= a[r])
            {
                return helper(a, m + 1, r, key);
            }

            return helper(a, l, m - 1, key);
        }
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        return helper(nums, l, r, target);
    }
};


class Solution2 {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        
        while ( l <= r) {
            
            int m = l + ( r -l) / 2;
            if ( nums[m] == target) {
                return m;
                
            }
           
            // it means l to m is sorted
            if ( nums[l] <= nums[m]) {
                if ( nums[l] <= target && nums[m] > target ) {
                    r = m - 1;
                }else {
                    l = m + 1;
                }
                
            }else {
                if ( nums[r] >= target && nums[m] < target) {
                    l = m + 1;
                }else {
                    r = m -1;
                }
            }
            
        }
        
        
        return -1;
        
        
        
        
    }
};