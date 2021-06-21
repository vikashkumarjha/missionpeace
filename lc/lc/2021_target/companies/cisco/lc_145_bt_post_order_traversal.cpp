vector<int> postOrder(TreeNode *root) 
{
    stack<TreeNode*> st;
    vector<int> result;
    TreeNode *last;
    while(root || !st.empty())
    {
            if ( root) {
                st.push(root);
                root = root->left;
            }
            else {
                TreeNode *curr = st.top();
                if ( curr->right && last != curr->right)
                {
                    root = curr->right;
                }
                else {
                    res.push_back(root->val);
                    last = curr;
                    st.pop();
                }
            }
    }
}
