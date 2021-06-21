Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

 

Example 1:

Input: x = 4
Output: 2
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.


class Solution {
public:
    int mySqrt(int x) {
        
        unsigned long long s = 0, e = x;
        unsigned long long m = 0;
        
        while (s < e) {
            m = s + (e-s)/2;

            if (m*m == x)
                return m;
            else if (m*m < x)
                s = m+1;
            else
                e = m;
        }
        
        return s*s > x ? s-1 : s;
    }
};