/*
 * Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

*/

class Solution {
private:

    void helper(TreeNode* root, std::string path, std::vector<std::string> &result){
        if ( !root ){
            return;
        }
        path += std::to_string(root->val);
        if ( !root->left && !root->right){
            result.push_back(path);
        }
        else {
            path += "->";
            helper(root->left, path, result);
            helper(root->right , path, result);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::string path;
        std::vector<std::string> result;
        helper(root, path , result);
        return result;
    }
};



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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        stack<string> pathStack;
        s.push(root);
        pathStack.push(to_string(root->val));

        while (!s.empty()) {
            TreeNode * curNode = s.top(); s.pop();
            string tmpPath = pathStack.top(); pathStack.pop();

            if (curNode->left == NULL && curNode->right == NULL) {
                res.push_back(tmpPath); continue;
            }

            if (curNode->left != NULL) {
                s.push(curNode->left);
                pathStack.push(tmpPath + "->" + to_string(curNode->left->val));
            }

            if (curNode->right != NULL) {
                s.push(curNode->right);
                pathStack.push(tmpPath + "->" + to_string(curNode->right->val));
            }
        }

        return res;
    }
};
