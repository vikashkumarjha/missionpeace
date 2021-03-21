/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
*/


class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0;
        long right = n;
        while ( left <= right){
            long mid = left + ( right - left ) / 2;
            if (( mid * ( mid + 1) / 2.0) <= n ) 
                left = mid +1;
            else 
                right = mid -1 ;
        }
        return right;
        
    }
};