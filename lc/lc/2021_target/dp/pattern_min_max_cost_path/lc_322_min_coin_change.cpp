#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for ( int i = 1; i <= amount; i++) {
            for ( int j = 0; j < n; j++) {
                if ( i >= coins[j] ) {
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        return ( dp[amount] > amount ? -1 : dp[amount]);
    }
};

int minCoins(vector<int> &coins, int m, int amount) {
    if ( amount == 0) return 0;
    int res = INT_MAX;
    for ( int i = 0; i < m; i++) {
        if ( coins[i] <= amount) {
            int subResult = minCoins(coins, m, amount - coins[i]);
            if ( subResult != INT_MAX) {
                res = min(res, subResult + 1);
            }
        }
    }
    return res;
}



int main()
{
    vector<int> coins = { 9, 6, 5, 1};
    int amount = 20;
    cout << "Minimum coins required:" << minCoins(coins, coins.size(), amount );
    return 0;
}
