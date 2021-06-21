/*
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 * */


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n,0);
        vector<int> rightMax(n,0);

        leftMax[0] = height[0];
        for ( int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];
        for ( int i = n - 2; i >= 0; i++) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        int waterHold = 0;
        for ( int i = 0; i < n; i++)
        {
            waterHold += min(leftMax[i], rightMax[i]) - height[i];
        }
        return waterHold;
    }

};


class Solution2{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int i = 0;
        stack<int> st;
        while ( i < height.size())
        {
            while (!st.empty() && height[i] > height[st.top()]) {
                int x = st.top(); st.pop();
                if ( st.empty()) break;
                int dist = i - st.top() - 1;
                int bounded_height = min(height[i], height[st.top()]) - height[x];
                ans += dist * bounded_height;

            }
            st.push(i);
            i++;
        }

    }
    return ans;
};
