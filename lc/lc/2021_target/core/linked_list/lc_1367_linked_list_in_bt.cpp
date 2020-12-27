/*
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

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