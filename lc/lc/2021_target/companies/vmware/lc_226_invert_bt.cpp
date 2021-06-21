class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> q;
        if ( !root)
            return root;
        q.push(root);
        while ( !q.empty()){
            auto curr = q.front();
            q.pop();
            std::swap(curr->left,curr->right);
            if ( curr->left){
                q.push(curr->left);
            }
            if (curr->right){
                q.push(curr->right);
            }
        }
        return root;
   
}
};