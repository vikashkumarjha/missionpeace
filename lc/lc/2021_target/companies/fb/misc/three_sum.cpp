//
//  three_sum.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/24/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

// we need to get all the combinations for the three sum...to zero...

vector<vector<int>> findThreeSum(vector<int> &nums) {
    std::set<vector<int>> resultSet;
    
    std::sort(nums.begin(), nums.end(), std::less<int>());
    
    for ( int i = 0; i < nums.size(); i++){
        size_t left = i + 1;
        size_t right = nums.size() - 1;
        while ( left < right){
            int currSum = nums[i] + nums[left] + nums[right];
            if ( currSum == 0 ){
                resultSet.insert({nums[i], nums[left], nums[right]});
                left++;
                right--;
                
            }else if ( currSum > 0 ){
                right--;
            }else {
                left++;
            }
        }
    }
    vector<vector<int>> r(resultSet.begin(), resultSet.end());
    return r;
    
    
}
