class BSTIterator {
private:
        std::stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        // when intializing the we should put the leftmost node..
        TreeNode *p = root;
        while ( p ){
            st.push(p);
            p = p->left;
        }
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (st.empty() != true);
        
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *currTop = st.top();
        st.pop();
        if ( currTop->right){

            TreeNode *p = currTop->right;
            while ( p ){
                st.push(p);
                p = p->left;
            }

        }
        return currTop->val;
        
    }
};