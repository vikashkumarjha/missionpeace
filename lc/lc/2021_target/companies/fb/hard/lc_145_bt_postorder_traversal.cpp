class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)
            return {};

        stack<TreeNode * > s;
        auto curr = root;
        vector<int> result;

        while(1){
            // Left Traversal with stack used for right
            while(curr){
                if (curr->right)
                    s.push(curr->right);
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top(); s.pop(); // root
            //// If the popped item has a right child and the right child is not 
            // processed yet, then make sure right child is processed before root 

            if (!s.empty() && curr->right && curr->right == s.top()){
                // Right Traversal
                s.pop(); // root->right
                s.push(curr); // push root back for later computation
                curr = curr->right;
            }
            else
            {
                result.push_back(curr->val);
                curr = nullptr;
            }

            if (s.empty())
                break;
        }

        return result;
    }
};
