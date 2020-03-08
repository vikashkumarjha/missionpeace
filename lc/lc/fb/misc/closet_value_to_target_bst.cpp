//
//  closet_value_to_target_bst.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/12/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#if 0

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if ( !root)
            return numeric_limits<int>::min();
        int closestVal =  root->val;
        while ( root) {
            if ( abs(root->val - target) <  abs(closestVal - target) ) {
                closestVal = root->val;
            }
            root = ( root->val < target) ? root->right : root->left;
         
        }
        return closestVal;
};
    
#endif 
