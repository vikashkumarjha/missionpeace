//
//  lc_1_two_sum.cpp
//  lc
//
//  Created by vikash kumar jha on 2/26/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0
#include "header.hpp"

using namespace std;


vector<int> twoSum(vector<int> &nums, int target) {
    if ( nums.empty()) return {};
    unordered_map<int,int> m;
    
    for ( int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if ( m.count(complement) && m[complement] != i) {
            return {m[complement], i};
        }
        
        m[nums[i]] = i;
        
    }
    
    return {};
    
}

#endif

