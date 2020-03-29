/*
Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.

 

Example 1:

Input: N = 3, K = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: N = 2, K = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,

*/

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1)
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
       
        vector<int> result;
        for (int i = 1; i <= 9; i++)
             generate(result, i, N - 1, K);
       
        return result;
    }
   
    void generate(vector<int> & result, int curint, int N, int K) {
        if (N == 0) {
            result.push_back(curint);
            return;
        }
       
        int lastdigit = curint % 10;
        if (lastdigit + K <= 9)
            generate(result, curint*10 + lastdigit + K,  N - 1,  K);
       
        if (lastdigit - K >= 0 && K)
            generate(result, curint*10 + lastdigit - K,  N - 1,  K);
    }
};