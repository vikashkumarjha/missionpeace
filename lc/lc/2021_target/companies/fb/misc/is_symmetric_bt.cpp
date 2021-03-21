//
//  is_symmetric_bt.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#if 0

#include <stdio.h>

bool isSymmetricHelper(TreeNode *left, TreeNode *right){
    
    if ( !left && !right){
        return true;
    }
    if ( !left || !right) {
        return false;
    }
    
    return ( left->val == right->val && isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left));
    
}



bool isSymmetric(TreeNode* root) {
    if (!root)
        return true;
 
    return isSymmetricHelper(root->left, root->right);
    
}
#endif
