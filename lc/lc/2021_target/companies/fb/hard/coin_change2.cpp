/*
You are given coins of different denominations and a total amount of money. 
Write a function to compute the number of combinations that make up that amount.
 You may assume that you have infinite number of each kind of coin.


*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
    vector<int> dp(amount+1, 0);
    dp[0] = 1;

    for (int coin : coins) {
      for (int x = coin; x < amount + 1; ++x) {
         dp[x] += dp[x - coin];
      }
    }
    return dp[amount];
        
    }
};