//
//  valid_palindrome_2.cpp
//  finishline
//
//  Created by vikash kumar jha on 2/6/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0


bool isValid(string s, int l, int r, int d) {
    if ( l >= r) return true;
    if ( s[l] == s[r])
        return isValid(s, l + 1, r - 1, d);
    
    return d > 0 && (isValid(s, l+1, r, d-1) || isValid(s, l, r-1, d-1));
    
}

bool validPalindrome(string s) {
    if ( s.empty() ) ret
    int r = s.size() - 1;
    int l = 0;
    
    return isValid(s, l, r, 1);
    
}

#endif
