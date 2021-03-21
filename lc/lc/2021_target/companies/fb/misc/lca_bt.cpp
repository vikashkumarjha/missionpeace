//
//  lca_bt.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/30/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>
#if 0

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return findLCAUtil(root,p,q);
        
    }
private:
    TreeNode* findLCAUtil(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if ( root == p || root == q || root == NULL)
                return root;
        TreeNode* leftParent = findLCAUtil(root->left,p,q);
        TreeNode* rightParent = findLCAUtil(root->right,p,q);
        if ( leftParent && rightParent)
            return root;
        return ( leftParent ? leftParent : rightParent );
        
        
    }
};
#endif
