//
//  lc_277_find_celebrity.cpp
//  lc
//
//  Created by vikash kumar jha on 2/27/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"

using namespace std;


int findCelebrity(int n) {
    if ( n <= 1) return n;
    int candidate= 0;
    
    for ( int i = 1; i < n; i++){
        if (knows(candidate, i)) {
            candidate = i;
        }
    }
    //candidate should not know anybody.
    
    for ( int i = 0; i < n; i++) {
        if ( i != candidate && knows(candidate, i) && !knows(i, candidate)) {
            return -1;
        }
        
    }
    
    return candidate;
    
}

#endif
    
    
    
    
