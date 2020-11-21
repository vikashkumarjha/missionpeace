//
//  two_sum.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/22/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include<vector>
#include<unordered_map>


using namespace std;

vector<int> two_sum(vector<int> &nums, int target) {
    
    unordered_map<int,int> m;
    
    for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if ( m.count(complement) && m[complement] != i ) {
            return vector<int> { m[complement], i};
            
        }
        m[nums[i]] = i;
    }
    return vector<int> {};
    
    
}


int main_two_sum()
{
    std::vector<int> v = { 1, 2, 3, 5,12 , 5, 11};
    
    vector<int> r = two_sum(v, 10);
    for ( auto x : r){
        std::cout << "the result" << x;
    }
    return 0;
    
}


