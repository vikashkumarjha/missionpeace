#include "../header.hpp"

class Solution {
public:
    int trap(vector<int>& h) {
        if (h.size() < 2) return 0;
        int water= 0;
        int n = h.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);

        leftMax[0] = h[0];
        for ( int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], h[i]);
        }
        rightMax[n-1] = h[n-1];
        for ( int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], h[i]);
        }

        for ( int i = 0; i < n; i++) {
            water += min(leftMax[i], rightMax[i]) - h[i];
        }

        return water;

    }
};

int main()
{
    vector<int> x = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    auto r = s.trap(x);
    cout << "\n The trapped value is" << r;


}
