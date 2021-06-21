/*
Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes, p and q. If either node p or q does not exist in the tree, return null. All values of the nodes in the tree are unique.

According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a binary tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)". A descendant of a node x is a node y that is on the path from node x to some leaf node.

 
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<TreeNode*, bool> res = hp(root, p, q);
        return res.second ? res.first : nullptr;
    }
    pair<TreeNode*, bool> hp(TreeNode* r, TreeNode* p, TreeNode* q) {
        if (!r) return {nullptr, false};
        pair<TreeNode*, bool> left = hp(r->left, p, q), right = hp(r->right, p, q);
        if (left.first && right.first)
            return {r, true};
        if (r == p || r == q)
            return {r, left.first || right.first};
        return left.first ? left : right;
    }
};