//
//  lc_94_bt_inorder_traversal.cpp
//  lc
//
//  Created by vikash kumar jha on 3/7/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//


#if 0

#include "header.hpp"
using namespace std;


vector<int> inorderTraversal(TreeNode *root) {
    
    if ( !root) return {};
    
    stack<TreeNode*> st;
    vector<int> result;
    TreeNode *curr = root;
    while ( true ) {
        while ( curr) {
            st.push(curr);
            curr = curr->left;
        }
        
        if ( st.empty()) break;
        
        curr = st.top(); st.pop();
        result.push_back(curr->val);
        
        curr = curr->right;
        
    }
    
    return result;
    
    
}

#endif
