/*
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
*/

#include "../header.hpp"


// complexity O(log  n)
//////              3
class Solution {
public:
    bool isPowerOfThree(int n) {
        if ( n < 0) return false;

        while ( n %3 == 0) {
            n /= 3;
        }
        return n == 1;
        
    }
};

//Approach 2
// n = 3 ^ i
// i = log3 (n)
// i = log 10 (n) / log 10 (3)

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x = 7.5, y = 2.1;
    double result = fmod(x, y);
    cout << "Remainder of " << x << "/" << y << " = " << result << endl;
    
    x = -17.50, y = 2.0;
    result = fmod(x, y);
    cout << "Remainder of " << x << "/" << y << " = " << result << endl;
    
    return 0;
}
//Remainder of 7.5/2.1 = 1.2
//Remainder of -17.5/2 = -1.5


class Solution2 {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
    }
};
