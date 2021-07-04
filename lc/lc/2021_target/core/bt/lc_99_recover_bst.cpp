You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

class Solution {
private :

    void inorderTraverse(struct TreeNode * root, vector<struct TreeNode *> & nodePtrList, vector<int>& nodeValList) {
        if (!root) return;

        inorderTraverse(root->left, nodePtrList, nodeValList);

        nodePtrList.push_back(root);
        nodeValList.push_back(root->val);

        inorderTraverse(root->right, nodePtrList, nodeValList);
    }

public:

    void recoverTree(struct TreeNode* root) {
        vector<int>  nodeValList;
        vector<struct TreeNode*> nodePtrList;

        inorderTraverse(root, nodePtrList, nodeValList);

        // Since InOrder should give us Sorted List of Elements
        //  -- 2 element are swapped, so sort value List
        sort(nodeValList.begin(), nodeValList.end());

        int idx = 0;
        for (const int val : nodeValList) {
            nodePtrList[idx]->val = val;
            idx++;
        }
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
private:
    TreeNode *f, *s, *p; // first, second, and previous

    void inorderTraversal(TreeNode *root) {
        if (!root)
            return;
        inorderTraversal(root->left);
        if (p && p->val >= root->val) {
            f = f ? f : p;
            s = root;
        }
        p = root;
        inorderTraversal(root->right);
    }

    void swap(TreeNode *f, TreeNode *s) {
        int t = f->val; f->val = s->val; s->val = t;
    }

public:
    void recoverTree(TreeNode* root) {
        f = NULL; s = NULL; p = NULL;
        inorderTraversal(root);
        swap(f, s);
    }
};
