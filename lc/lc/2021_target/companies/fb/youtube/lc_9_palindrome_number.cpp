//
//  lc_9_palindrome_number.cpp
//  lc
//
//  Created by vikash kumar jha on 3/7/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

/*
 Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

 Example 1:

 Input: 121
 Output: true
 Example 2:

 Input: -121
 Output: false
 Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 Example 3:

 Input: 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 */


#if 0

#include "header.hpp"



bool isPalindrome(int x) {
    
    int num = 0;
    int curr = x;
    
    while ( curr ) {
        num *= 10;
        num  +=  curr % 10;
        curr /= 10;
    }
    return ( num == x);
    
    
    
    
}


/*
 
 https://leetcode.com/problems/reverse-integer/
 Given a 32-bit signed integer, reverse digits of an integer.

 Example 1:

 Input: 123
 Output: 321
 Example 2:

 Input: -123
 Output: -321
 Example 3:

 Input: 120
 Output: 21
 */



class Solution {
public:
    int reverse(int x) {
    int result = 0;

    while ( x ){
        int d = x % 10;
        if ( result > INT_MAX / 10 || (result == INT_MAX && d > 7))
            return 0;

        if ( result <  INT_MIN / 10 || (result == INT_MIN && d < -8))
            return 0;
        
        result = result * 10 + d;
        x /= 10;
    }
    return result;

}

};

#endif
