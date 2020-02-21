//
//  lcs.cpp
//  lc
//
//  Created by vikash kumar jha on 2/21/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#include "header.hpp"

using namespace std;

// find the lcs of two strings..


#if 0

int helper(string &a, string &b, int n1 , int n2) {
    if ( n1 < 0 || n2 < 0) return 0;
    
    if ( a[n1] == b[n2]) {
        return 1 + helper(a, b, n1-1, n2-1);
    }else {
        return max (helper(a, b , n1 - 1, n2) , helper(a, b , n1, n2-1));
    }
    
}


int lcs(string a , string b) {
    
    int n1 = a.length();
    int n2 = b.length();
    
    return helper(a, b, n1-1, n2 -1 );
    
}


int main() {
    std::cout << "we will solving the problem.";
    string a = "aabbcxyz";
    string b = "abczmn";
    
    std::cout << "\n result " << lcs(a,b);
    return 0;
    
}

#endif
