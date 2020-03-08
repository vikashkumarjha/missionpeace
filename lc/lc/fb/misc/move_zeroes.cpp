//
//  move_zeroes.cpp
//  finishline
//
//  Created by vikash kumar jha on 2/4/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

//https://leetcode.com/problems/move-zeroes/

/*
283. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <functional>
#include <numeric>


using namespace std;

#if 0

void moveZeroes(vector<int>& nums) {
    int writeIndex = 0;
    int N = nums.size();
    for ( auto n : nums) {
        if ( n != 0 ) {
            nums[writeIndex] = n;
            writeIndex++;
        }
    }
    for ( int k = writeIndex; k < N; k++) {
        nums[k] = 0;
    }
    
    
     
}

int main() {
    std::cout << "we will be solving the move zeroes...";
    vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    std::for_each(nums.begin(), nums.end(), [](int x){
        std::cout << x << " ";
    });
    
    return 0;
}

#endif



