//
//  next_permutation.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/12/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int pos = static_cast<int>(nums.size() - 1);
    bool flag = true;
    
    while ( pos > 0) {
        if ( nums[pos-1] >= nums[pos]) {
            pos--;
            continue;
        }
        else {
        
            auto tmp = nums[pos-1];
            swap(nums[pos-1], nums[pos]);
        
            for ( int i = pos; i < nums.size(); i++) {
                // find the numer which is greater than what we replaced and less than its replacement.
                if ( nums[i] > tmp && nums[i] < nums[pos-1]){
                    swap(nums[pos-1], nums[i]);
                }
            
            }
        
            std::sort(nums.begin() + pos, nums.end());
            flag = false;
            break;
        }
        
    }
    if ( flag) {
        sort(nums.begin(), nums.end());
    }
    
    
}

int main_next_permutation() {
    
    vector<int> nums = { 1, 1, 5, 2,1};
    nextPermutation(nums);
    std::for_each(nums.begin(), nums.end(),[](int x){
        std::cout << x << " ";
    });
    
    
    return 0;
}
