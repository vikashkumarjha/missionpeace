/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include "../header.hpp"

typedef vector<vector<int>> ROWS;
class Solution {

private:
    void helper(vector<int> nums, int l, int r, ROWS &result) {
        if ( l == r )  {
            result.push_back(nums);
        }
        for ( int k = l; k <= r; k++) {
            swap(nums[k], nums[l]);
            helper(nums, l + 1, r , result);
            swap(nums[k], nums[l]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        int l = 0;
        int r = nums.size() - 1;
        helper(nums, l, r, result);

        for ( auto row : result) {
            cout << "\n";
            for (auto c : row) {
                cout << c << " ";
            }
        }

        return result;
        
    }
};


int main()
{
    Solution s;
    vector<int> nums = { 1, 2,3};
    s.permute(nums);
}