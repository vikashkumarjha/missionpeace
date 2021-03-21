/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 

Example:



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // return 3
iterator.next();    // return 7
iterator.hasNext(); // return true
iterator.next();    // return 9
iterator.hasNext(); // return true
iterator.next();    // return 15
iterator.hasNext(); // return true
iterator.next();    // return 20
iterator.hasNext(); // return false

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
