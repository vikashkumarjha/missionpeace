/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

 
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class BSTIterator {
private:
stack<TreeNode*> st;

public:
    BSTIterator(TreeNode* root) {
        TreeNode *curr = root;
        while ( curr ) {
            st.push(curr);
            curr = curr->left;
        }
        
    }
    
    /** @return the next smallest number */
    int next() {
        if (!st.empty()) {
            TreeNode *curr = st.top(); st.pop();
            if ( curr->right) {
                TreeNode *p = curr->right;
                while ( p ){
                    st.push(p);
                    p = p->left;
                } 
            }
        }
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return ( st.empty() != true);
    }
};