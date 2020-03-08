//
//  lc_101_symmetric_tree.cpp
//  lc
//
//  Created by vikash kumar jha on 3/7/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

/*
 https://leetcode.com/problems/symmetric-tree/
 
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

 For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

     1
    / \
   2   2
  / \ / \
 3  4 4  3
  

 But the following [1,2,2,null,3,null,3] is not:

     1
    / \
   2   2
    \   \
    3    3
 
 */


#if 0

#include "header.hpp"

using namespace std;

bool helper(TreeNode *l, TreeNode *r) {
    if ( !l && !r) {
        return true;
    }
    
    if ( !l || !r) {
        return false;
    }
    
    return (l->val == r->val) && helper(l->left, r->right) && helper(l->right , r->left);
    
    
}



bool isSymmetric(TreeNode* root) {
    
    if ( !root)
        return true;
    
    
    return helper(root->left,root->right);
    
}


public boolean isSymmetric(TreeNode root) {
    Queue<TreeNode> q = new LinkedList<>();
    q.add(root);
    q.add(root);
    while (!q.isEmpty()) {
        TreeNode t1 = q.poll();
        TreeNode t2 = q.poll();
        if (t1 == null && t2 == null) continue;
        if (t1 == null || t2 == null) return false;
        if (t1.val != t2.val) return false;
        q.add(t1.left);
        q.add(t2.right);
        q.add(t1.right);
        q.add(t2.left);
    }
    return true;
}


#endif
