/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []

*/
#include "../header.hpp"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> result;
        int n = nums.size();
        if ( n == 0) {
            return {{}};
        }
        sort(nums.begin(), nums.end());
        for ( int i = 0; i < n - 2; i++) {
            auto l = i + 1;
            int  r = n - 1;

            while ( l < r) {
                auto s = nums[i] + nums[l] + nums[r];
                if ( s == 0 ) {
                    result.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if ( s > 0 ) {
                    r--;
                } else {
                    l++;
                }
            }
        }

        vector<vector<int>> ret(result.begin(), result.end());
        return ret;
    }
};
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if ( n == 0) {
            return {{}};
        }
        sort(nums.begin(), nums.end());
        for ( int i = 0; i < n - 2; i++) {
            if ( i == 0 || (i > 0 && nums[i] != nums[i-1])) {
            auto l = i + 1;
            int  r = n - 1;

            while( l < r) {
                auto s = nums[i] + nums[l] + nums[r];
                if ( s == 0 ) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    while ( l < r && nums[l] == nums[l+1]) l++;
                    while ( l < r && nums[r] == nums[r-1]) r--;
                    l++;
                    r--;
                }
                else if ( s > 0 ) {
                    r--;
                } else {
                    l++;
                }
            }
        }
    }
    return result;
}
};


int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution2 s;
    auto r = s.threeSum(nums);
    for ( auto row : r) {
        cout << "\n[ ";
        for ( auto c : row) {
            cout << c << " ,";
        }
        cout << " ]";
    }
    return 0;

}


