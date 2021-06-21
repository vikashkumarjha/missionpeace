class Solution {
public:
    bool verifyPreorder(vector<int>& pre) {
        stack<int> st;
        int n = pre.size();
        int root = INT_MIN;
        
        
        for ( int i = 0; i < n; i++) {
            if ( pre[i] < root) {
                return false;
            }
            
            while (!st.empty() && st.top() < pre[i]) {
                root = st.top();
                st.pop();
                
            }
            st.push(pre[i]);
            
        }
        
        return true;
        
        
    }
};