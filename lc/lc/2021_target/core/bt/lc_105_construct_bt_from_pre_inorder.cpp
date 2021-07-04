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
    TreeNode *helper(vector<int> &pre, vector<int> &in, int &rootIdx, int l, int r) {
        if ( l > r) return nullptr;

        int rootVal = pre[rootIdx];

        cout << "\n The value of" << rootVal;
        int pivot = l;
        while ( in[pivot] != rootVal) pivot++;

        TreeNode *root = new TreeNode(rootVal);
        rootIdx++;
        root->left = helper(pre, in, rootIdx, l, pivot - 1);
        root->right = helper(pre, in, rootIdx,  pivot+1, r);

        return root;


    }



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int rootIdx = 0;

        return helper(preorder, inorder, rootIdx, 0, n - 1);


    }
};
