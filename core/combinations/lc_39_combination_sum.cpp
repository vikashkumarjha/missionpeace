/*
 * Given an array of distinct integers candidates and a target integer target,
 * return a list of all unique combinations of candidates where the chosen
 * numbers sum to target. You may return the combinations in any order.
 *
 * The same number may be chosen from candidates an unlimited number of times.
 * Two combinations are unique if the frequency of at least one of the chosen
 * numbers is different.
 *
 * */

#include "../../stdc++.h"
using namespace std;



void combinationSumHelper(vector<int> &cand, int idx, vector<int> &comb, int target , vector<vector<int>> &res)
{
    if (!target)
    {
        res.push_back(comb);
        return;
    }
    for ( int i = idx; i < cand.size() && cand[i] <= target; i++)
    {
        comb.push_back(cand[i]);
        combinationSumHelper(cand, i, comb, target - cand[i], res);
        comb.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int> &cand, int target)
{
    sort(begin(cand), end(cand));
    vector<int> combination;
    vector<vector<int>> res;
    combinationSumHelper(cand, 0, combination, target, res);
    return res;
}

int main()
{
    vector<int> x =  {2,3,6,7};
    int target = 7;

    vector<vector<int>> res = combinationSum(x, 7);

    for ( auto row : res)
    {
        cout << "\n";
        for_each(begin(row), end(row), [](int x) {
                cout << x << " "; });
    }
    return 0;
}
