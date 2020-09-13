/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

*/

#include "../header.hpp"

class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        if ( n < 2) return 0;
        int l = 0;
        int r = n - 1;
        int maxArea = 0;

        while ( l < r) {
            maxArea = max(maxArea, ( r - l) * min(h[l], h[r]));
            if ( h[l] > h[r]) {
                r--;
            }else {
                l++;
            }
        }
        return maxArea;
        
    }
};

int main()
{
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    Solution s;
    auto r = s.maxArea(h);
    cout << "\n The value of the max area" << r;
    return 0; 


}