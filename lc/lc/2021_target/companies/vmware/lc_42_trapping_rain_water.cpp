class Solution {
public:
    int trap(vector<int>& height)
{
    int ans = 0, i = 0;
    stack<int> st;
    while (i < height.size()) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = i - st.top() - 1;
            int bounded_height = min(height[i], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(i);
        i++;
    }
    return ans;
}
};


class Solution {
public:
    int trap(vector<int>& h) {
        if ( h.empty()) return 0;
        
        int res = 0;
        int n = h.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = h[0];
        rightMax[n-1] = h[n-1];
        
        for ( int i = 1; i < n; i++) {
            leftMax[i] = max(h[i], leftMax[i-1]);
        }
        
        for ( int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(h[i], rightMax[i+1]);
        }
        
        
        for ( int i = 0; i < n; i++) {
           
            res += min(leftMax[i], rightMax[i]) - h[i];
            
        }
        
        return res;
        
       
        
        
    }
};