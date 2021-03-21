//
//  coin_change.cpp
//  lc
//
//  Created by vikash kumar jha on 2/24/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"

using namespace std;



// we are given infinite supply of coin supply for each denominations.
// find the total number of ways to make the particular sum.



int countWays(vector<int> &nums, int n, int s) {
    if ( s == 0 ) return 1;
    if ( s < 0) return 0;
    if ( n <= 0 && s > 0) return 0;
    
    return countWays(nums, n - 1, s) + countWays(nums, n , s - nums[n-1]);
    
  
    
}


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




int main() {
    std::cout << "\n We will be solving the coin change problem.";
    vector<int> coins = { 1, 2, 3};
    int N = coins.size();
    int target = 4;
    
    
    int ways = countWays(coins, N, target);
    std::cout << "\n Total number of ways:" << ways;
    
    
    return 0;
}

#endif
