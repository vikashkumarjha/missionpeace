/*
 *Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


 */

#include "header.hpp"
using namespace std;


int largestRectangleArea(vector<int>& heights) {
    if ( heights.empty() ) return 0;
    heights.push_back(0);
    stack<int> st;

    int maxArea = 0;
    for ( int i = 0; i < heights.size(); i++) {
        while ( !st.empty() && heights[st.top()] >= heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int w =  st.empty() ? i : i - 1 - st.top();
            maxArea = std::max(maxArea, h * w);
        }
        st.push(i);

    }
    return maxArea;

}


int main() {

    vector<int> heights = {2,1,5,6,2,3};
    std::cout << "\n The max area:" << largestRectangleArea(heights) << std::endl;
    return 0;


}
