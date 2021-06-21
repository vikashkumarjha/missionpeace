class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1;
        int end = -1;
        
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
            {
                if(mid == 0 || nums[mid-1] < nums[mid])
                {
                    start = mid;
                    break;
                }
                else
                    high = mid-1;
            }
            else if(nums[mid] < target)
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
        }
        
        low = 0;
        high = nums.size() - 1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] == target)
            {
               if(mid == nums.size()-1 || nums[mid+1] > nums[mid])
                {
                    end = mid;
                    break;
                }
                else
                    low = mid+1;
            }
            else if(nums[mid] < target)
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
        }
 
        return {start, end};
    }
};