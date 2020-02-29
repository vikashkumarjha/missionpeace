//
//  lc_121_best_time_to_buy_sell.cpp
//  lc
//
//  Created by vikash kumar jha on 2/25/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//



#if 0
#include "header.hpp"
using namespace std;

// we can do at most one trasaction.

int maxProfit(vector<int> & prices) {
    if ( prices.empty()) return 0;
    int minPrice = prices[0];
    int maxProfit = 0;
    for ( int i = 1; i < prices.size(); i++) {
        if ( prices[i] < minPrice) {
            minPrice = prices[i];
        }
        maxProfit = max( maxProfit, prices[i] - minPrice);
    }
    
    return maxProfit;
    
}


int main() {
    vector<int> p = {7,1,5,3,6,4};
    
    auto r = maxProfit(p);
    
    std::cout << "\n Max Profit:" << r;
    
    return 0;
    
}

#endif
