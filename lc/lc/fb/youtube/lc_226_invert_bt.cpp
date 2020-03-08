//
//  lc_226_invert_bt.cpp
//  lc
//
//  Created by vikash kumar jha on 3/7/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//
/*
 nvert a binary tree.

 Example:

 Input:

      4
    /   \
   2     7
  / \   / \
 1   3 6   9
 Output:

      4
    /   \
   7     2
  / \   / \
 9   6 3   1
 */


#if 0

#include "header.hpp"

using namespace std;


TreeNode* invertTree(TreeNode* root) {
    if ( !root)
        return root;
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);
    return root;
    
    
}


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> q;
        if ( !root)
            return root;
        q.push(root);
        while ( !q.empty()){
            auto curr = q.front();
            q.pop();
            std::swap(curr->left,curr->right);
            if ( curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
        return root;
   
}
};

#endif



