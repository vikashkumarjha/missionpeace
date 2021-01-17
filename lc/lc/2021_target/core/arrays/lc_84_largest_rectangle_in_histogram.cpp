/*
Given n non-negative integers representing the histogram's bar height where 
the width of each bar is 1, find the area of largest rectangle in the histogram.

*/



class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        if ( h.empty()) return 0;
        
        stack<int> st;
        h.push_back(0);
        int res = 0;
        
        for ( int i = 0; i < h.size(); i++) {
            
            while ( !st.empty() && h[i] < h[st.top()]){
                int l = h[st.top()];
                st.pop();
                
                int w = ( st.empty()) ? i : i - 1 - st.top();
                res = max(res, l * w);
                
            }
            
            st.push(i);  
        }
        
        return res;
        
        
    }
};