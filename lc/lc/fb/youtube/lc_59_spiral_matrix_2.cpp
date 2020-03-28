class Solution {
public:
    vector<vector<int> > generateMatrix(int n) { 
        vector<vector<int> > m(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1, num = 1;
        while(true) {
            // up
            for(int col = left; col <= right; col++) 
                m[top][col] = num++;
            if(++top > bottom) break;
            // right
            for(int row = top; row <= bottom; row++) 
                m[row][right] = num++;
            if(--right < left) break;
            // down
            for(int col = right; col >= left; col--) {
                m[bottom][col] = num++;
            }
            if(--bottom < top) break;
            // left
            for(int row = bottom; row >= top; row--) {
                m[row][left] = num++;
            }
            if(++left > right) break;
        }
        return m;
    }
};