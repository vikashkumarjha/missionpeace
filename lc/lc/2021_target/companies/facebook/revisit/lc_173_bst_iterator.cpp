/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */