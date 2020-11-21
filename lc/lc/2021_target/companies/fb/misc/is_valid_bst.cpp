//
//  is_valid_bst.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/30/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>

using namespace std;
#if 0
// here we need to check

bool isValidBstHelper(TreeNode *root, TreeNode *minNode, TreeNode *maxNode){
    if (!root){
        return true;
    }
    if ( minNode && root->val < minNode->val  || maxNode && root->val >= maxNode->val){
        return false;
    }
    
    return isValidBstHelper( root->left, minNode, root ) && isValidBstHelper( root->right, root, minNode );
    
}



bool isValidBst(TreeNode* root){
    
    return isValidBstHelper(root, nullptr, nullptr);
    
}

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long pre = LONG_MIN;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            st.pop();
            if (root -> val <= pre) {
                return false;
            }
            pre = root -> val;
            root = root -> right;
        }
        return true;
    }
};
#endif

