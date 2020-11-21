/*
 * Given a binary matrix A, we want to flip the image horizontally, then invert
 * it, and return the resulting image.
 *
 * To flip an image horizontally means that each row of the image is reversed.
 * For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].
 *
 * To invert an image means that each 0 is replaced by 1, and each 1 is replaced
 * by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
 *
 * Example 1:
 *
 * Input: [[1,1,0],[1,0,1],[0,0,0]]
 * Output: [[1,0,0],[0,1,0],[1,1,1]]
 * Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
 * Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
 *
 * */

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int nr = A.size();
        int nc = A[0].size();
        for ( int c = 0; c < (nc+1) / 2; c++)
        {
            for ( int r = 0; r < nr; r++)
            {
                int tmp = A[r][c] ^ 1;
                A[r][c] = A[r][nc-1-c] ^ 1;
                A[r][nc-1-c] = tmp;
            }
        }
        return A;

    }
};
