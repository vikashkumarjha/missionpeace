/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

*/

#include "../../header.hpp"


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       int n = coins.size();
       vector<int> dp(amount+1, amount+1);
       dp[0] = 0;
       for ( int i = 1; i <= amount; i++) {
           for ( int j = 0; j < coins.size(); j++) {
               if (i >= coins[j]) {
                dp[i] = min(dp[i], dp[i-coins[j]]+1);                               
               }
           }

       }

       return ( dp[amount] > amount ? -1 : dp[amount]);

        
    }
};

class Solution {
public:
    int helper(vector<int> &coins, int n, int amount) {
        if ( amount == 0) {
            return 0;
        }
        
        if ( amount < 0) return INT_MAX;
        
        int res = INT_MAX;
        
        for ( int i = 0; i < n; i++) {
            
            int subResult = helper(coins, n, amount - coins[i] );
            if ( subResult != INT_MAX) {
                res = min(res, subResult + 1);
            }
            
        }
        
        
        return res;
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        
        int res = helper(coins, coins.size(), amount);
        if ( res != INT_MAX) {
            return res;
        }
        
        return -1;
        
    }
};

