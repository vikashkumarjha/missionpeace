//
//  lc_896_monotonic_array.cpp
//  lc
//
//  Created by vikash kumar jha on 2/28/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.

//
/*
 An array is monotonic if it is either monotone increasing or monotone decreasing.

 An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
 */

#if 0

#include "header.hpp"
using namespace std;

bool isMonotonic(vector<int>& A) {
    int N = A.size();
    bool inc = true;
    bool dec = true;
    
    for ( int i = 0; i < N - 1 && (inc || dec); i++ ) {
        if ( A[i] > A[i+1]) inc = false;
        if ( A[i] < A[i+1]) dec = false;
        
    }
    
    return (inc || dec);
    
}

#endif
