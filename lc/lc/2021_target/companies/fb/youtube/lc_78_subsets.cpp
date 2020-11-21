/*
 * Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int numSubset = std::pow(2,nums.size());
        std::vector<std::vector<int> > res(numSubset, std::vector<int>());
        for ( int counter = 0; counter < numSubset ; ++counter)
        {
            for ( int j = 0; j < nums.size(); ++j)
            {
                if ( counter & (1 << j))
                {
                    res[counter].push_back(nums[j]);
                }
            }
        }
        return res;

    }
};


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        subsets(nums, 0, sub, subs);
        return subs;
    }
private:
    void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
        subs.push_back(sub);
        for (int j = i; j < nums.size(); j++) {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, sub, subs);
            sub.pop_back();
        }
    }
};
