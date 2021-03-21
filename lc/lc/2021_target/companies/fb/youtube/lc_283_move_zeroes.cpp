//
//  lc_283_move_zeroes.cpp
//  lc
//
//  Created by vikash kumar jha on 2/26/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0

#include "header.hpp"

// move zeroes at the end of the array.

using namespace std;

void moveZeroes(vector<int> &nums) {
    int N = nums.size();
    
    int writeIdx = 0;
    for ( auto n : nums) {
        if (n != 0 ) {
            nums[writeIdx] = n;
            writeIdx++;
        }
    }
    
    for ( int i = writeIdx; i < N; i++) {
        nums[i] = 0;
    }
    
}

#endif


