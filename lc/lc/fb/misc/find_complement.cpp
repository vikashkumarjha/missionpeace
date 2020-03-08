//
//  find_complement.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/27/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#if 0
class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};
For example,

num          = 00000101
mask         = 11111000
~mask & ~num = 00000010

#endif
