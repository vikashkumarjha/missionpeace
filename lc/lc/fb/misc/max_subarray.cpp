//
//  max_subarray.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/24/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <vector>
#include<string>
#include<vector>
using namespace std;


int max_subarray(vector<int> &v){
    if ( !v.size())
        return INT_MIN;
    
    
    // at each point decide between current element and sum till now + curr
    
    int curr_sum = v[0];
    int max_sum_so_far = v[0];
    for ( int i = 1; i < v.size(); i++){
        curr_sum = max(v[i], curr_sum + v[i]);
        max_sum_so_far = max(max_sum_so_far, curr_sum );
        std::cout << "\n " << curr_sum << "::" << max_sum_so_far;
    }
    return max_sum_so_far;
}



int main_5(){
    
    
    vector<int> v = { 1, 2,-1, 10, -10};
    
    //lets get the max subarray...
    
    int result = max_subarray(v);
    
    std::cout << "\n the result" << result;
    
    
    
    
    
    return 0;
    
    
}
