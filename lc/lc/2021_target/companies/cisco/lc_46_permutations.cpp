/*
 * Given an array nums of distinct integers, return all the possible
 * permutations. You can return the answer in any order.
 *
 *
 *
 *  Example 1:
 *
 *  Input: nums = [1,2,3]
 *  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 *  Example 2:
 *
 *  Input: nums = [0,1]
 *  Output: [[0,1],[1,0]]
 *  Example 3:
 *
 *  Input: nums = [1]
 *  Output: [[1]]
 *
 * */


void helper(int idx, vector<int> &nums, vector<vector<int>> &res)
{
    if ( idx == nums.size())
    {
        res.push_back(nums);
        return;
    }
    for ( int k = idx; k < nums.size(); k++)
    {
        swap(nums[k], nums[idx]);
        helper(idx+1, nums, res);
        swap(nums[k], nums[idx]);
    }
}


vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    if (nums.empty()) return res;

    helper(0, nums, res);

    return res;

}
