//
//  bt_level_order_traversal.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#if 0

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root){
        return result;
    }
    
    
    queue<TreeNode*> q;
    
    q.push(root);
    
    while (!q.empty()){
        size_t qSize = q.size();
        if (row.size() == 0)
            break;
        vector<int> row;
        	
        while ( qsize--){
            
            auto curr = q.front();
            q.pop();
            q.push(curr->val);
            if ( curr->left){
                q.push(curr->left);
            }
            if ( curr->right){
                q.push(curr->right);
            }
            
        }
        result.push_back(row);
    }
    
    return result;
    
    
}
#endif
