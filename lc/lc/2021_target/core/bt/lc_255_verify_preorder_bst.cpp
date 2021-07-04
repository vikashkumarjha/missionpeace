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


bool canRepresentBST(int pre[], int n)
{
    // Create an empty stack
    stack<int> s;

    // Initialize current root as minimum possible
    // value
    int root = INT_MIN;

    // Traverse given array
    for (int i=0; i<n; i++)
    {
        // If we find a node who is on right side
        // and smaller than root, return false
        if (pre[i] < root)
            return false;

        // If pre[i] is in right subtree of stack top,
        // Keep removing items smaller than pre[i]
        // and make the last removed item as new
        // root.
        while (!s.empty() && s.top()<pre[i])
        {
            root = s.top();
            s.pop();
        }

        // At this point either stack is empty or
        // pre[i] is smaller than root, push pre[i]
        s.push(pre[i]);
    }
    return true;
}
 
