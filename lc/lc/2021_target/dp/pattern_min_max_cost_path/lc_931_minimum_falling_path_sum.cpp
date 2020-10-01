/*
 * Given a square array of integers A, we want the minimum sum of a falling path
 * through A.
 *
 * A falling path starts at any element in the first row, and chooses one
 * element from each row.  The next row's choice must be in a column that is
 * different from the previous row's column by at most one.
 *
 *
 *
 *  Example 1:
 *
 *  Input: [[1,2,3],[4,5,6],[7,8,9]]
 *  Output: 12
 *  Explanation:
 *  The possible falling paths are:
 *  [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
 *  [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
 *  [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
 *
 *  */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if ( A.empty()) return 0;

        int R =  A.size();
        int C =  A[0].size();

        for ( int r = 1; r < R; r++) {
            for ( int c = 0; c < C; c++) {
                A[r][c] = A[r][c] + min(A[r-1][c], min(A[r-1][max(0,c-1)], A[r-1][min(C-1, c+1)]));
            }
        }

        int res = INT_MAX;

        for ( auto x : A[R-1]) {
            res = min(res, x);
        }
        return res;


    }
};

int main()
{
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    int r = s.minFallingPathSum(A);
    cout << "\n The result" << r;
    return 0;

}
