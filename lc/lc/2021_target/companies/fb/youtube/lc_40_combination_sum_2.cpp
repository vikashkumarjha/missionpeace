#include "header.hpp"
using namespace std;

/*
 * After careful thought, I think this kind of backtracking contains a iterative
 * component and a resursive component so I'd like to give more details to help
 * beginners save time. The revursive component tries the elements after the
 * current one and also tries duplicate elements. So we can get correct answer
 * for cases like [1 1] 2. The iterative component checks duplicate combinations
 * and skip it if it is. So we can get correct answer for cases like [1 1 1] 2.
 *
 * */



void helper(vector<int> &candidates, int index, vector<int> &current, int target,  vector<vector<int>> &result ) {
    if ( !target) {
        result.push_back(current);
        return;
    }

    for ( int i = index; i < candidates.size() && target >= candidates[i]; i++) {
        //check for repetition
        if ( i && candidates[i] == candidates[i-1] && i > index) continue;
        current.push_back(candidates[i]);
        helper(candidates, i + 1, current, target - candidates[i], result);
        current.pop_back();

    }

}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    std::sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<int> current;

    helper(candidates, 0,  current, target, result);
    return result;

}

int main() {
    vector<int> candidates = {  2,2,2,2,2};
    vector<vector<int>> result = combinationSum(candidates, 4);
    for ( auto r : result) {
        std::for_each(r.begin(), r.end(), [](int x) {
                std::cout << x << " ";
                });
        std::cout << "\n";
    }

    return 0;
}
