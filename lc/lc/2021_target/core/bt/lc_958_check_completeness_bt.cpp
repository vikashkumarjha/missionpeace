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
    bool isCompleteTree(TreeNode* root) {
        bool pre = true;
        queue<TreeNode*> nq;
        nq.push(root);

        while(!nq.empty()){
            TreeNode* node = nq.front();
            nq.pop();

            if(node == NULL){
                pre = false;
            }
            else{
                if(pre == false)
                    return false;

                nq.push(node->left);
                nq.push(node->right);
            }

        }

        return true;
    }
};
