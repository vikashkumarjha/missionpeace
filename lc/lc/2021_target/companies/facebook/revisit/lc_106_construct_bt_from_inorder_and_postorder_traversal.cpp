/*

post order last node is the root...

Let us see the process of constructing tree from in[] = {4, 8, 2, 5, 1, 6, 3, 7} and post[] = {8, 4, 5, 2, 6, 7, 3, 1} 
1) We first find the last node in post[]. The last node is “1”, we know this value is root as root always appear in the end of postorder traversal.
2) We search “1” in in[] to find left and right subtrees of root. Everything on left of “1” in in[] is in left subtree and everything on right is in right subtree. 

         1
       /    \
[4, 8, 2, 5]   [6, 3, 7]
3) We recur the above process for following two. 
….b) Recur for in[] = {6, 3, 7} and post[] = {6, 7, 3} 
…….Make the created tree as right child of root. 
….a) Recur for in[] = {4, 8, 2, 5} and post[] = {8, 4, 5, 2}. 
…….Make the created tree as left child of root.

*/


class Solution {
    
      TreeNode* helper(vector<int> &postorder, vector<int> &inorder, int postStart, int postEnd, int inStart, int inEnd){
        if ( postStart > postEnd || inStart > inEnd)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        if (postStart == postEnd)
            return root;
        
        else {
            int val = postorder[postEnd];
            int idx = -1;
            for ( int k = inStart; k <= inEnd; k++) {
                if ( val == inorder[k]) {
                    idx = k;
                    break;
                }
            }
            
            int rightLen = inEnd - idx + 1;
            int leftLen = inorder.size() - rightLen;
            
            root->left = helper(postorder, inorder, postStart, postEnd - rightLen, inStart, idx - 1);
            
            root->right = helper(postorder, inorder, postStart + leftLen - 1, postEnd - 1, idx + 1, inEnd);
            
            return root;
            
         
            
        }
        
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
          // find the index of 
        int postStart = 0;
        int postEnd = postorder.size() - 1;
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        
        return helper(postorder, inorder, postStart, postEnd, inStart, inEnd);
        
    }
};