/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

 

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/

/*

Now the strategy is here:

Add coins one-by-one, starting from base case "no coins".

For each added coin, compute recursively the number of combinations for each amount of money from 0 to amount.

Algorithm

Initiate number of combinations array with the base case "no coins": dp[0] = 1, and all the rest = 0.

Loop over all coins:

For each coin, loop over all amounts from 0 to amount:

For each amount x, compute the number of combinations: dp[x] += dp[x - coin].
Return dp[amount].



*/


/*
The fun part about this solution is that if you switch the order of the for loops in the code, your answer almost doubles! Learnt it the hard way.

If you're wondering why, here's a hint:

To make an amount of 3 with two coin denominations 1 and 2, you can go:
1 + 2 = 3
2 + 1 = 3
Both mean the same thing, in this question.

*/

#include "../header.hpp"


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
