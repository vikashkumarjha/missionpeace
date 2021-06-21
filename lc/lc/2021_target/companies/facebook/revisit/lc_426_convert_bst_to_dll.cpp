
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        stack<Node*> st;
        Node *first = nullptr;
        Node *last = nullptr;
        
        while (root || !st.empty()) {
            while ( root) {
                st.push(root);
                root = root->left;
            }
            
            Node *curr = st.top(); st.pop();
            if ( !first) {
                first = curr;
            }
            
            if (last) {
                last->right = curr;
                curr->left = last;
            }
            
            last = curr;
            root = curr->right;
            
            
        }
        first->left = last;
        last->right = first;
        return first;
        
    }
};