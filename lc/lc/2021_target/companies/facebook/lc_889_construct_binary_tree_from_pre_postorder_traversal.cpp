/*
Given two arrays that represent preorder and postorder traversals of a full binary tree, construct the binary tree.
A Full Binary Tree is a binary tree where every node has either 0 or 2 children
Following are examples of Full Trees. 

        1
      /   \
    2       3
  /  \     /  \
 4    5   6    7


       1
     /   \
   2      3
        /   \  
       4     5
           /   \  
          6    7
                  

          1
        /   \
      2       3
    /  \     /  \
   4    5   6    7
 /  \  
8    9 


It is not possible to construct a general Binary Tree from preorder and postorder traversals (See this). But if know that the Binary Tree is Full, we can construct the tree without ambiguity. Let us understand this with the help of following example.
Let us consider the two given arrays as pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7} and post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1}; 
In pre[], the leftmost element is root of tree. Since the tree is full and array size is more than 1. The value next to 1 in pre[], must be left child of root. So we know 1 is root and 2 is left child. How to find the all nodes in left subtree? We know 2 is root of all nodes in left subtree. All nodes before 2 in post[] must be in left subtree. Now we know 1 is root, elements {8, 9, 4, 5, 2} are in left subtree, and the elements {6, 7, 3} are in right subtree. 

                  1
                /   \
               /      \
     {8, 9, 4, 5, 2}     {6, 7, 3}


*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *helper(vector<int>& pre, vector<int>& post, int &preStart, int postStart, int postEnd) {
        if ( postStart > postEnd) return nullptr;
        
        TreeNode *root = new TreeNode(pre[preStart]);
        preStart++;
       
        if ( postStart == postEnd) return root;
        int idx = postStart;
        for ( int k = postStart; k <= postEnd; k++) {
            if ( post[k] == pre[preStart]){
                idx = k;
                break;
            }
        }
        
        root->left = helper(pre, post, preStart, postStart, idx);
        root->right = helper(pre, post, preStart, idx + 1, postEnd - 1);
       
        return root;
      
    }
    
        
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if ( pre.size() != post.size()) return nullptr;
        
        int preStart = 0;
        int preEnd = pre.size() - 1;
        int postStart = 0;
        int postEnd = post.size() - 1;
        
        
        TreeNode *root = helper(pre, post, preStart, postStart, postEnd);
        
        return root;
    
    }
};