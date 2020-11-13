#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x) : val(x), next(nullptr) {}
};

 struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



class Solution {

public:
    int getLength(ListNode *head) {
        int count = 0;
        ListNode *curr = head;
        while ( curr) {
            count++;
            curr = curr->next;

        }
        return count;

    }


    TreeNode *helper(ListNode **head, int n) {
        if ( n <= 0 )return nullptr;
        TreeNode *ptrL = helper(head, n/2);
        TreeNode *root = new TreeNode((*head)->val);
        *head = (*head)->next;
        TeeNode *ptrR = helper(head, n - n/2 - 1);

        root->left = ptrL;
        root->right = ptrR;

        return root;

    }


    TreeNode* sortedListToBST(ListNode *head) {
        if ( !head ) return nullptr;
        int n = getLength(head);
        return helper(&head, n);

    }



}
