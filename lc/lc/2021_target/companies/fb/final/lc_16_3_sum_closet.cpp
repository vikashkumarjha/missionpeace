class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        std::sort(nums.begin(),nums.end());
        int dist = INT_MAX;
        int closetSum = 0;
        for ( int i = 0; i < nums.size(); ++i)
        {

            int left = i+1;
            int right = nums.size()-1 ;
            while ( left < right)
            {
                int currsum = nums[i] + nums[left] + nums[right];
                int diff = std::abs(currsum - target);
                if ( diff < dist )
                {
                    dist = diff;
                    closetSum = currsum;
                }
                if ( currsum > target )
                {
                    --right;
                }
                else if ( currsum < target)
                {
                    ++left;
                }
                else
                    return target;
            }
        }
        return closetSum;


    }
};
