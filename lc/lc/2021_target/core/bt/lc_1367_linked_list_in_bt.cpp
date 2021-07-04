/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:    

    bool helper(ListNode* head, TreeNode* root) {

        if (!head) return true;
        if (!root) return false;
        if (head->val != root->val ) return false;

        // Here we are going to both The PATHS
        return helper(head->next, root->left) || helper(head->next, root->right);
    }    

public:

    bool isSubPath(ListNode* head, TreeNode* root) {
        // Here head is start node in Tree
        // Check if All elements in LinkList form SUB-PATH is BT Tree.

        if (!head) return true;
        if (!root) return false;

        if (helper(head, root)) return true;  

        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
