class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        if ( mat.empty()) return res;
        int R = mat.size();
        int C = mat[0].size();
        bool moveUp = true;

        int r = 0;
        int c = 0;

        while ( r < R && c < C && r >= 0 && c >= 0) 
        {
            res.push_back(mat[r][c]);
            if ( r == R - 1 && c == C - 1) break;
            if ( moveUp) {
                if ( r >= 1 && c + 1 < C ) {
                    r--;
                    c++;
                }
                else if (c+1 < C) {
                    c++;
                    moveUp = false;
                }else {
                    r++;
                    moveUp = false;
                }

            }else {
                if ( r < R - 1 && c >= 1) {
                    r++;
                    c--;
                }
                else if ( r < R - 1) {
                    r++;
                    moveUp = true;
                }
                else {
                    c++;
                    moveUp = true;
                }

            }



        }
        return res;



    }
};
