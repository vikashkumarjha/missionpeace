//
//  lc_461_hamming_distance.cpp
//  lc
//
//  Created by vikash kumar jha on 2/28/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0
#include "header.hpp"
using namespace std;

// we can use the property of xor bit operation.
// when the bit are same then xor opearion gives zero otherwise 1.


 int hammingDistance(int x, int y) {
     int diffBits = x ^ y;
     int count = 0;
     
     while ( diffBits) {
         count++;
         diffBits = diffBits & (diffBits - 1);
     }
     
     return count;
 }

#endif
   
