class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        
         int left;
        int right;
        int start = 0;
        int end = nums.size();

        // we will find the left...

        while ( start < end )
        {

                int m = (start + end) / 2;

                if ( nums[m] >= target )
                {
                        end = m;
                }
                else
                {
                        start = m + 1;
                }
        }
        left = start;
        start = 0;
        end = nums.size();
        while ( start < end )
        {
                int m = (start + end) / 2;

                if ( nums[m] > target )
                        end = m;
                else
                       start = m + 1;
        }

        right = start;
        return ( left == right) ? std::vector<int> { - 1, -1 } : vector<int> {left,right-1};
        
    }
};