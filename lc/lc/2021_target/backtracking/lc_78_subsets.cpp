/*
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 *
 * Note: The solution set must not contain duplicate subsets.
 *
 * Example:
 *
 * Input: nums = [1,2,3]
 * Output:
 * [
 *   [3],
 *     [1],
 *       [2],
 *         [1,2,3],
 *           [1,3],
 *   [2,3],
 *     [1,2],
 *   []
 * ]
 * */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:

    void helper(vector<int> &nums, int idx, vector<int> &sub, vector<vector<int>> &res) {
        res.push_back(sub);
        for ( int i = idx; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            helper(nums, i + 1, sub, res);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        helper(nums, 0, sub, res);
        return res;

    }
};



class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int numSubset = pow(2,nums.size());
        vector<vector<int> > res(numSubset, std::vector<int>());
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


int main()
{
    vector<int> nums = { 1, 2,3};
    Solution2 s;
    vector<vector<int>> rows = s.subsets(nums);

    for ( auto r : rows) {
        for_each( begin(r), end(r), [](int x) {
                cout << x << " ";
                });

        cout << "\n";
    }
    return 0;

}
