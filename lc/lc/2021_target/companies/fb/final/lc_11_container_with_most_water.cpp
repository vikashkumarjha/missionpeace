class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0;
        int r = n - 1;
        int res = INT_MIN;

        while ( l < r){
            int lHeight = h[l];
            int rHeight = h[r];

            res = max(res, min(lHeight, rHeight) * (r - l));

            if (lHeight >  rHeight) {
                r--;
            }else {
                l++;
            }

        }
        return res;

    }
};
