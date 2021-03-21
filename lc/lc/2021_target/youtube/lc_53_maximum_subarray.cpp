#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if ( nums.empty()) return 0;
        int curr = nums[0];
        int maxSum = nums[0];
        for ( int i = 1; i < nums.size(); i++) {
            curr = max(nums[i], curr + nums[i]);
            maxSum = max(maxSum, curr );
        }

        return maxSum;

    }

    int helper(vector<int> &nums, int l, int r) {
        if ( l > r) return INT_MIN;
        int m = l + ( r - l) / 2;
        int lmax = helper(nums, l, m - 1);
        int rmax = helper(nums, m+1, r);

        int sum = 0, ml = 0, mr = 0;
        for ( int i = m-1; i >= l; i--) {
            sum += nums[i];
            ml = max(ml, sum);
        }
        sum = 0;
        for ( int i = m + 1; i <= r; i++) {
            sum += nums[i];
            mr = max(mr, sum);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }


    int maxSubArrayDivideAndConquer(vector<int>& nums) {
        if ( nums.empty()) return 0;
        return helper(nums, 0, nums.size() - 1);
    }
};


int main()
{
   vector<int> v =  {1,2,3,4,5};
   Solution s;
   int r = s.maxSubArrayDivideAndConquer(v);
   std::cout << "\n The value of the rsult" << r;
   return 0;
}
