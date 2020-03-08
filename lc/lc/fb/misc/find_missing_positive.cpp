//
//  find_missing_positive.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>
#if 0

int firstMissingPositive(vector<int>& nums) {
    if ( nums.size() == 0)
        return 1;
    
    int positiveMax = nums.size();
    set<int> s;
    
    for ( auto n : nums){
        if ( n > 0 ){
            s.insert(n);
        }
    }
    
    if ( s.empty()){
        return 1;
    }
    
    for ( int i = 1; i <= positiveMax; ++i)
    {
        if ( s.find(i) == s.end() )
            return i;
        
    }
    return positiveMax + 1;
   
    
}
#endif
