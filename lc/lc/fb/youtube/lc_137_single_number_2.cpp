//
//  lc_137_single_number_2.cpp
//  lc
//
//  Created by vikash kumar jha on 2/28/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#include "header.hpp"

using namespace std;

#if 0
/*

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
 */

// Approach 1
int singleNumber(vector<int>& nums) {
    unordered_map<int, int> m;
    for ( auto n : nums) {
        m[n]++;
    }
    
    for ( auto e : m ) {
        if ( e.second == 1) return e.first;
        
    }
    return -1;
    
}

// Approach 2
int singleNumber2(vector<int>& nums) {
    set<int> s(nums.begin(), nums.end());
    int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
    int setSum = std::accumulate(s.begin(), s.end(), 0);
    
    int candiate = ((3 * setSum ) - totalSum)/ 2;
    
    return candiate;
    
    
}

// Approach 3

/*
 To separate number that appears once from a number that appears three times let's use two bitmasks instead of one: seen_once and seen_twice.

 The idea is to

 change seen_once only if seen_twice is unchanged

 change seen_twice only if seen_once is unchanged
 */

int singleNumber3(vector<int> &nums) {
    int seenOnce = 0;
    int seenTwice = 0;
    
    for ( auto n : nums ) {
        seenOnce = ~seenTwice && ( seenOnce ^ n);
        seenTwice = ~seenOnce && ( seenTwice ^ n);
    
    }
    
    return seenOnce;
   
}

#endif

