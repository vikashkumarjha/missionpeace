#include "header.hpp"


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        
        for ( int i = 0; i < heights.size(); i++) {
            while ( !st.empty() && heights[i] < heights[st.top()] ) {
                int l = heights[st.top()];
                st.pop();
                
                int w = ( st.empty()) ? i : i - 1 - st.top();
                res = max(res, l * w);
                
                
            }
            st.push(i);
            
        }
        return res;
        
    }
};