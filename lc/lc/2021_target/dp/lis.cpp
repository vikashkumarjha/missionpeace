//
//  lis.cpp
//  lc
//
//  Created by vikash kumar jha on 2/21/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0
#include "header.hpp"

using namespace std;

int lis(vector<int> &v) {
    
    int N = v.size();
    if ( N == 0) return 0;
    vector<int> DP(N, 1);
    
    DP[0] = 1;
    
    for ( int i = 1; i < N; i++) {
        for ( int j = 0; j < i; j++) {
            if ( v[j] < v[i] && DP[i] < DP[j] + 1  ) {
                DP[i] = DP[j] + 1;
            }
        }
    }
    
    return *max_element(DP.begin(), DP.end());
    
}



int main() {
    
    vector<int> v = { 1, 2, 3, 4, 5, 1,2};
    
    int r = lis(v);
    std::cout << "\n The longest increasing " << r;
    
    
    
}

#endif
