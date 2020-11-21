vector<string> binaryTreePaths(TreeNode* root) {

    string path;
    vector<string> res;

    helper(root, path, res);
    return res;
}

void helper( TreeNode *root, string path, vector<string> &res) {
    if ( !root)
        return;
    path += to_string(root->val);
    if ( !root->left && !root->right) {
        res.push_back(path);
        return;
    }
    path += "->";
    helper(root->left, path, res);
    helper(root->right, path, res);
}



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