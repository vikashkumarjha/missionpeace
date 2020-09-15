/*
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

 

Example 1:

Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

*/

#include "../header.hpp"

typedef unsigned int uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int mask = 1;

        for ( int i = 0; i < 32; i++) {
            if ( n & mask) {
                count++;
            }
            mask = mask <<  1;
        }
        return count;
        
    }
};
class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while ( n ) {
            count++;
            n = n & (n-1);
        }
        return count;
        
    }
};




int main()
{
    vector<uint32_t> inputs = { 1, 7, 16, 32, 15};
    Solution2 s;
    for ( auto n : inputs) {
        cout << "\n " << n << "has bit count : " << s.hammingWeight(n);
    }
    return 0;

}