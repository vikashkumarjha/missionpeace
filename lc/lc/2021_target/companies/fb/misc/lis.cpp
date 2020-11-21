//
//  lis.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    vector<int> dp(nums.size(), 0);
    dp[0] = 1;
    for ( int i = 1; i < nums.size(); i++){
        
        for ( int j = 0; j < i; j++){
            if ( nums[i] > nums[j]){
                dp[i] =  max(dp[i] , dp[j]+1);
            }
        }
        
    }
    return *max_element(nums.begin(), nums.end());
    
}
