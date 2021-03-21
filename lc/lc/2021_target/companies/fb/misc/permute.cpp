//
//  permute.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/24/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// lets print all permutations...
void permute(vector<int> &nums, int l, int r , vector<vector<int>> &result){
    if ( l == r ){
        result.push_back(nums);
        return;
    }
    for ( auto index = l; index <= r; index++){
        std::swap(nums[l], nums[index]);
        permute(nums,l+1, r, result);
        std::swap(nums[l], nums[index]);
    }
    
}


int main_12()
{
    vector<int> nums = { 1, 2, 3};
    vector<vector<int>> result;
    
    permute(nums, 0, static_cast<int>(nums.size() - 1),  result);
    for ( auto r : result){
        for ( auto c : r ){
            std ::cout <<  c << " ";
        }
        std::cout << "\n";
    }
    return 0;
}



