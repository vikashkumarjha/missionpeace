#include "../header.hpp"
using namespace std;



class Solution {
public:

    void helper(vector<int> nums, int l, int r, vector<vector<int>> &res) {
        if ( l == r) {
            res.push_back(nums);
            return;
        }
        for ( int i = l; i <= r; i++) {
            swap(nums[i], nums[l]);
            helper(nums, l+1, r, res);
            swap(nums[i], nums[l]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int l = 0;
        int r = nums.size() - 1;
        helper(nums, l, r, res);
        return res;

    }
};



int main()
{
    vector<int> nums = { 1, 2, 3};
    Solution s;
    vector<vector<int>> res = s.permute(nums);
    for ( auto r : res) {
        for_each(r.begin(), r.end(), [](int x) {
                cout << x  << " ";
                });

        cout << "\n";
    }
    return 0;

}
