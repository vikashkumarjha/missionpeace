/*
Given a square array of integers A, we want the minimum sum of a falling path through A.

A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.

 

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: 12
Explanation: 
The possible falling paths are:
[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]

*/


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
       int R = A.size();
       int C = R ? A[0].size() : 0;
       
        for(int i = 1; i < R; i++) {
            for(int j = 0; j < C; j++) {
                A[i][j] += min(A[i - 1][j],
                               min(A[i - 1][max(0, j - 1)],
                                   A[i - 1][min(C - 1,j + 1)]));
            }
        }
       
        int minFallPath = INT_MAX;
        for(auto x : A[R - 1])
            minFallPath = min(minFallPath, x);
       
        return minFallPath;
    }
};