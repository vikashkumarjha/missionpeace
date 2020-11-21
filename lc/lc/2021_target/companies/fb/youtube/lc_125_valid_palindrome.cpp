//
//  lc_125_valid_palindrome.cpp
//  lc
//
//  Created by vikash kumar jha on 2/28/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0
#include "header.hpp"
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if ( s.empty())
            return true;
        int l = 0;
        int r = s.size() - 1;
        while ( l < r) {
            while ( l < r && !isalnum(s[l]))
                l++;
            while ( l < r && !isalnum(s[r])){
                r--;
            }
            if ( tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
            
        }
        return true;
        
        
    }
};

#endif
