//
//  lc_118_pascal_triangle.cpp
//  lc
//
//  Created by vikash kumar jha on 3/7/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//



#if 0
#include "header.hpp"
using namespace std;




vector<vector<int>> generate(int numRows) {
    vector<vector<int>> t;
    if ( numRows <= 0) return t;
    for ( int r = 1; r <= numRows; r++) {
        vector<int> currRow(r, 1);
        t.push_back(currRow);
    }
    
    // Now i will generate the pascal triangle.
    
    
    for ( int i = 2; i < numRows; i++) {
        for ( int j = 1; j < i; j++) {
            t[i][j] = t[i-1][j-1] + t[i-1][j];
        }
        
    }
    return t;
   
}


#endif
