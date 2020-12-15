/*

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.


*/

#include "../header.hps"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> candidates;
    for (int i=1; i<10; i++)
        candidates.push_back(i);
    vector<vector<int>> res;
    vector<int> nums;
    dfs(candidates, k, n, 0, nums, res);
    return res;
}

void dfs(vector<int>& candidates, int k, int target, int index, vector<int>& nums, vector<vector<int>>& res) {
    if (target < 0 || k < 0)
        return;
    if (target == 0 && k == 0) {
        res.push_back(nums);
        return;
    }
    for (unsigned int i=index; i<candidates.size(); i++) {
        nums.push_back(candidates[i]);
        dfs(candidates, k-1, target-candidates[i], i+1, nums, res);
        nums.pop_back();
    }
}
};