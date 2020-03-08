//
//  lc_112_has_path_sum.cpp
//  lc
//
//  Created by vikash kumar jha on 3/7/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

/*
 https://leetcode.com/problems/path-sum/
 
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

 Note: A leaf is a node with no children.

 Example:

 Given the below binary tree and sum = 22,

       5
      / \
     4   8
    /   / \
   11  13  4
  /  \      \
 7    2      1
 
 */


#if 0



class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)   return false;
        if(root->val == sum && !root->left && !root->right)  return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        
    }
};


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return false;
        std::queue<TreeNode*> q;
        q.push(root);
        std::queue<int> sums;
        sums.push(0);
        while(q.size())
            for(int i = 0,n = sums.size();i < n;++i) {
                auto ptr = q.front();
                q.pop();
                int _sum = sums.front() + ptr->val;
                sums.pop();
                if(ptr->left == nullptr && ptr->right == nullptr) {
                    if(_sum == sum)
                        return true;
                    
                }
                if(ptr->left) {
                    q.push(ptr->left);
                    sums.push(_sum);
                }
                if(ptr->right) {
                    q.push(ptr->right);
                    sums.push(_sum);
                }
            }
        return false;
    }
};

#endif
