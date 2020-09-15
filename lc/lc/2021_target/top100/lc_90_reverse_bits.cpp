/*
Reverse bits of a given 32 bits unsigned integer.

 

Example 1:

Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 
represents the unsigned integer 43261596, 
so return 964176192 which its binary representation is 
00111001011110000010100101000000.

*/

// key to this 
/*
The key idea is that for a bit that is situated at the index i, after the reversion, its position should be 31-i (note: the index starts from zero).

We iterate through the bit string of the input integer, from right to left (i.e. n = n >> 1). To retrieve the right-most bit of an integer, we apply the bit AND operation (n & 1).

For each bit, we reverse it to the correct position (i.e. (n & 1) << power). Then we accumulate this reversed bit to the final result.

When there is no more bits of one left (i.e. n == 0), we terminate the iteration.


*/

class Solution {
public:
    unsigned int reverseBits(unsigned int n) {
        unsigned int ret = 0;
        int power = 31;
        while ( n != 0) {
            ret += ( n & 1) << power; // rightmost bit move to correct pos
            n = n >> 1;
            power--;
        }
        return ret;
        
    }
};