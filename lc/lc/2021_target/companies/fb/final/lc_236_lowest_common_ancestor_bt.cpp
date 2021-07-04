/*
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

class Solution {
public:

    void findPath(TreeNode * root, vector<TreeNode *>&path, TreeNode* &node, bool& flag)
    {
        path.push_back(root);
        if(root->val==node->val)
        {
            flag = true;
            return;
        }

        if(root->left)findPath(root->left,path,node,flag);
        if(flag)return;
        if(root->right)findPath(root->right,path,node,flag);
        if(!flag)path.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> pPath;
        vector<TreeNode*> qPath;
        bool flag = false;
        findPath(root,pPath,p,flag);
        flag = false;
        findPath(root,qPath,q,flag);

        int pn = pPath.size();
        int qn = qPath.size();
        int i,j;
        i = 0;
        j = 0;
        TreeNode * res;
        while(i<pn && j<qn)
        {
            if(pPath[i]->val==qPath[i]->val)
            {
                res = pPath[i];
                i++;
                j++;
            }
            else
                break;
        }

        return res;
    }
};

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode *p, TreeNode *q) {
        if ( !root ) return nullptr;

        if ( root == p || root == q) return root;

        auto leftLca = helper(root->left, p, q);
        auto rightLca = helper(root->right, p, q);

        if ( leftLca && rightLca) return root;

        return (leftLca ? leftLca : rightLca);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);

    }
};
