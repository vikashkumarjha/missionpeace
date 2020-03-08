//
//  valid_palindrome.cpp
//  finishline
//
//  Created by vikash kumar jha on 11/26/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 Note: For the purpose of this problem, we define empty string as valid palindrome.

 Example 1:

 Input: "A man, a plan, a canal: Panama"
 Output: true
 Example 2:

 Input: "race a car"
 Output: false
 */
// we have to consider only alphanumeric and ignore cases...

bool isPalindrome(string s) {
   
    
    int l = 0;
    int r = s.length() - 1;
    
    while ( l <= r ) {
            // skip any non-alphanumeric characters...
        while ( l < r && !isalnum(s[l])) {
            l++;
        }
        while ( l < r && !isalnum(s[r])) {
            r--;
        }
        if ( s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
        
    }
    return true;
    
    
}
