//
//  lc_102_bt_level_order_traversal.cpp
//  lc
//
//  Created by vikash kumar jha on 3/1/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"

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


 vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>> t;
     if ( !root) return t;
     
     queue<TreeNode*> q;
     q.push(root);
     
     while ( !q.empty()) {
         auto qsize = q.size();
         vector<int> r;
         while ( qsize--) {
             auto curr = q.front(); q.pop();
             r.push_back(curr->val);
             if ( curr->left) {
                 q.push(curr->left);
             }
             if ( curr->right) {
                 q.push(curr->right);
             }
             
         }
         t.push_back(r);
         
     }
     return r;
     
 }

#endif
