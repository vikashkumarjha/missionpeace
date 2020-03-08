//
//  bt_max_pathsum.cpp
//  finishline
//
//  Created by vikash kumar jha on 11/26/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#if 0

#include <stdio.h>
// path does not have to include root...
#include<iostream>

int max_gain(TreeNode* root, int &result) {
    if ( !root)
        return 0;
    int left_gain = max(max_gain(root->left), 0);
    int right_gain = max(max_gain(root->right), 0);
    
    int curr_path_sum = left_gain + root->val + right_gain;
    result = max(result, curr_path_sum);
    
    return root->val + max(left_gain, right_gain);

}

int maxPathSum(TreeNode* root) {
    int result = INT_MIN;
    max_gain(root, result);
    
        
}

#endif
