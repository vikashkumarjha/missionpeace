#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        if ( prices.empty()) return 0;
        int n = prices.size();

        int currPrice = prices[0];
        for ( int i = 1; i < n; i++) {
            res = max(prices[i] - currPrice, res);
            currPrice = min(currPrice, prices[i]);
        }

        return res;
        
        
    }
};


int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    Solution s;
    int r = s.maxProfit(prices);
    cout << "\n Max Profit:" << r;
    return 0;

}