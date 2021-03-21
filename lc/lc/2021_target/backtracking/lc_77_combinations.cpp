#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        helper(1, n, k, comb, res);
        return res;
    }
    void helper(int curr, int n, int k , vector<int> comb, vector<vector<int>> &res) {
        if ( k == 0) {
            res.push_back(comb);
            return;
        }
        // exclude
        if ( curr <= n - k) helper(curr+1, n , k, comb, res);
        // include
        comb.push_back(curr);
        helper(curr+1, n, k -1, comb, res);
    }

};

int main()
{
    Solution s;
    vector<vector<int>> res = s.combine(4,2);
    for ( auto r : res) {
        cout << "\n";
        for_each(begin(r), end(r), [](int x) {
                cout << x << " "; });
    }
    return 0;

}
