//
//  lc_122_buy_sell_stock_2.cpp
//  lc
//
//  Created by vikash kumar jha on 2/28/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"
using namespace std;

// we can do multiple transaction but at the same time two transation
// can not be going on.
// so the idea for every valley get the peak

//Time Complexity O(n ^ n) and space complexity O(n)

int calculate(vector<int> &prices, int index) {
    if ( index >= prices.size()) return 0;
    int maxResult = 0;
    
    for ( int start = index; start < prices.size(); start++) {
        int profit = 0;
        for ( int end = start + 1; end < prices.size(); end++) {
            if ( prices[start] < prices[end]) {
                profit = calculate(prices, end+1) + (prices[end] - prices[start]);
            }
        }
        maxResult = max(maxResult, profit);
        
    }
    
    return maxResult;
    
    
}

int maxProfit(vector<int>& prices) {
    if ( prices.empty()) return 0;
    
    return calculate(prices, 0);
    
}

// Approach 2
// This approach

int maxProfit2(vector<int>& p) {
    int N = p.size();
    if ( N == 0) return 0;
    int profit = 0;
    int valley = p[0];
    int peak = p[0];
    int i = 0;
    
    while ( i < N - 1) {
        // Get the valley.
        while ( i < N - 1 && p[i] >= p[i+1]) {
            i++;
        }
        
        valley = p[i];
        
        // Get the peak.
        
        while ( i < N - 1 && p[i] < p[i+1]) {
            i++;
        }
        peak = p[i];
        profit += peak - valley;
       
    }
    
    return profit;
    
    
}


// Approach 3


int maxProfit3(vector<int>& p) {
    int profit = 0;
    int N = p.size();
    for ( int i = 1; i < N; i++) {
        if ( p[i] > p[i-1]) {
            profit += (p[i] - p[i-1]);
        }
    }
    return profit;
    
    
}


#endif
