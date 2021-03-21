//
//  hamming_distance.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/27/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

// hamming distance is defined as the number of bit which are different in two integers

#if 0
class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned long diffbits = x ^ y;

        int result = 0;

        while ( diffbits )
        {
                ++result;
                diffbits &= diffbits - 1;
        }
        return result;
        
    }
};

#endif
