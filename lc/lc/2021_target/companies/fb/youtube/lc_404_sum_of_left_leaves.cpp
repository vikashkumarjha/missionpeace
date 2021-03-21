//
//  lc_404_sum_of_left_leaves.cpp
//  lc
//
//  Created by vikash kumar jha on 2/29/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//



#if 0
#include "header.hpp"
using namespace std;



int sumOfLeftLeaves(TreeNode* root, int flag) {
    if ( !root)
        return 0;
    
    if ( !root->left && !root->right && flag) {
        return root->val;
    }
    
    return (root->left, 1) + (root->right, 0);
    
    
}



class Solution {
public:
    void helper(TreeNode* root, int& sum){
        if ( !root )
            return;
        if ( root->left){
            if ( !root->left->left && !root->left->right){
                sum += root->left->val;
            }
            helper(root->left, sum);
        }
        if ( root->right){
            helper(root->right,sum);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root,sum);
        return sum;
    }

};



int main() {
    return sumOfLeftLeaves(root,sum);
    
}

#endif
