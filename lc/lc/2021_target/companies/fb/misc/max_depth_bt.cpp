//
//  max_depth_bt.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//
#if 0
#include <stdio.h>

 int maxDepth(TreeNode* root) {
     if (!root)
         return 0;
     int lDepth = maxDepth(root->left);
     int rDepth = maxDepth(root->right);
     
     return ( lDepth > rDepth) ? lDepth + 1 : rDepth + 1;
     
 }
#endif
