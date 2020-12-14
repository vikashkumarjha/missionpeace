/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

*/

#include "../header.hpp"

class Solution
{
private:
    void
    helper(int idx, vector<int> &nums, vector<vector<int>> &result)
    {
        if (idx == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int k = idx; k < nums.size(); k++)
        {
            swap(nums[idx], nums[k]);
            helper(idx + 1, nums, result);
            swap(nums[idx], nums[k]);
        }
    }

public:
    vector<vector<int>>
    permute(vector<int> &nums)
    {
        if (nums.empty())
            return {};

        vector<vector<int>> result;

        helper(0, nums, result);

        return result;
    }
};


int main()
{
    Solution sol;
    vector<int> a = {1,2,3};
    vector<vector<int>> res = sol.permute(a);

    for (auto r : res) {
        cout << "\n";
        for_each(begin(r), end(r), [](int x) {
            cout << x << " ";
        });
    }
    return 0;
}