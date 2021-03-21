/*

Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1

*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int N = s.size();
       
        if (N == 1) {
            return -1;
        }
   
         /* find the first decreasing digit from the right, eg: 59876, 5 is the first decreasing digit */
        int start = -1;
        for (int i = N - 2; i >= 0; --i) {
            if (s[i] < s[i+1]) {
                start = i;
                break;
            }
        }
       
        // if a decreasing digit cannot be find, the number cannot be larger.
        if (start == -1)
            return -1;
       
        reverse(s.begin() + start + 1, s.end());
       
        // XXX5 + 6789
        for (int i = start + 1; i < N; ++i) {
             if (s[i] > s[start]) {
                 swap(s[i], s[start]);
                 break;
             }      
        }
       
        long result = stol(s);
       
        return (result == n || result > INT_MAX) ? -1 : result;
    }
};
