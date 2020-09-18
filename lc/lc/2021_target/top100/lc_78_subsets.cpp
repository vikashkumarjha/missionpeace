/*
Given a set of distinct integers, nums, return all possible subsets (the power set).
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

#include "../header.hpp"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if ( nums.size() == 0) return result;
        int numOfSubset = pow(2, nums.size());

        for (  int i = 0; i < numOfSubset; i++) {
            vector<int> curr;
            for ( int j = 0; j < nums.size(); j++) {
                if ( i & (1 << j)) {
                    curr.push_back(nums[j]);
                }
            }
            result.push_back(curr);
        }
        return result;
    }
};


//O(2 ^ N) N IS THE INPUT SIZE
// visualize this
//  []
//  [1]
//  [1 2]
//  [1 2 3]
//  [1 3]
//  [2]
//  [2 3]
//  [3]
class SolutionBacktrack {
private:
    void helper(vector<int> &A, vector<int> &current, int index, vector<vector<int>> &result) {
        result.push_back(current);

        for ( int i = index; i < A.size();i++)
        {
            //include
            current.push_back(A[i]);
            helper(A, current, i+1, result);
            //exlude
            current.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> current;
        helper(nums, current, 0, result);
        return result;
    }
};



int main()
{
    vector<int> x = { 1, 2,3};
    SolutionBacktrack s;
    auto result = s.subsets(x);
    for ( auto r : result){
        cout << endl;
        cout << "[";
        for ( auto c : r )
            cout << c << " ";
        cout << "]";
    }
    return 0;
}
