#include<iostream>
#include<vector>

using namespace std;


/*
 * he big O of these question are complicated and hard to analize. But according to some resource, all the combination problems are derived to be O(2^N), N is the number of element. (let s = target / min(nums[i]) T = C(s,1) + C(s, 2) + ... + C(s, s) = 2^s) You can think of this answer as for each element it got two choices, to be chosen or not to be chosen.
 *
 * */


void combinationSumHelper(vector<int>& candidates, vector<int> &path, const int& target , int start, vector<vector<int>> &combinations )
{
    if ( target < 0 ){
        return;
    }
    else if ( target == 0 ){
        if ( path.empty() ) return;
        combinations.push_back(path);
        return;
    }else {
        for ( int i = start; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            // ** if u want duplicate then
            combinationSumHelper(candidates, path, target - candidates[i], i, combinations);
            //else
            //combinationSumHelper(candidates, path, target - candidates[i], i+1, combinations);
            path.pop_back();
        }
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, const int& target) {
    vector<vector<int>> combinations;
    vector<int> path;
    // sort the numbers
    std::sort(candidates.begin(), candidates.end());
    combinationSumHelper(candidates, path, target, 0, combinations);
    return combinations;
}



int main_100()
{
    vector<int> candidates =  { 1, 2,3,4, 5};
    vector<vector<int>> result = combinationSum(candidates,5);

    for ( auto r : result ){
        std::cout << "[";
        for ( auto c : r) {
            std::cout << c << ",";
        }
        std::cout << "]\n";
    }
    return 0;

}
