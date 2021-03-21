//
//  count_ways_to_cover_distance.cpp
//  lc
//
//  Created by vikash kumar jha on 2/21/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"

using namespace std;

// can take either 1 , 2 or 3 steps.

int countWays(int n) {
    if ( n < 0 ) return 0;
    if ( n == 0 ) return 1;
    
    return countWays(n-1) + countWays(n - 2) + countWays(n-3);
    
}

int countWaysDP(int n ) {
    vector<int> DP(n+1);
    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;
    
    for ( int i = 3; i <= n; i++) {
        
        DP[i] = DP[i-1] + DP[i-2] + DP[i-3];
    }
    
    return DP[n];
    
}


int main() {
    std::cout << "\n The number of  ways:" << countWays(3) << "::" << countWaysDP(3);
    return 0;
}

#endif






