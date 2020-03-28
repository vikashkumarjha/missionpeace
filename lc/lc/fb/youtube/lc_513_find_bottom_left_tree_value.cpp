class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int leftMostNode;
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                TreeNode* top = q.front();
                q.pop();
                leftMostNode = top->val;
                if (top->right) q.push(top->right);
                if (top->left) q.push(top->left);
            }
        }

        return leftMostNode;

    }
};


class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::pair<int,int> result{0,0};
        helper(root, result,1);
        return result.second;

    }
    void helper(TreeNode* root, std::pair<int,int> &result, int level)
    {
        if ( !root)
            return;
        helper(root->left,result,level+1);
        if ( !root->left && !root->right){
            if ( level > result.first){
                result.first = level;
                result.second = root->val;
            }

        }
        helper(root->right,result,level+1);
    }
};
