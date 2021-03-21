/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0).
 Find two lines, which, together with the x-axis forms a container, 
 such that the container contains the most water.

Notice that you may not slant the container.

*/

#include "header.hpp"s


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