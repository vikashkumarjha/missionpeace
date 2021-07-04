class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode *curr = root;
        while ( curr) {
            st.push(curr);
            curr = curr->left;
        }

    }

    int next() {
        TreeNode *x = st.top(); st.pop();
        if (x->right) {
            TreeNode *p = x->right;
            while ( p ) {
                st.push(p);
                p = p->left;
            }
        }
        return x->val;

    }

    bool hasNext() {
        return (st.size() != 0);
    }
private:
    stack<TreeNode*> st;
};

