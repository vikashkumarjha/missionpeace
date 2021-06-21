class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if ( !root) return res;
        stack<Node*> st;
        st.push(root);
        
        while ( !st.empty()) {
            auto curr = st.top(); st.pop();
            res.push_back(curr->val);
            int n = curr->children.size();
            while (n--) {
                st.push(curr->children[n]);
            }
            
        }
        return res;
        
    }
};