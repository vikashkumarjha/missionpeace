class Solution {
private:
    
    int getLength(struct ListNode * root) {
        int count = 0;        
        while (root) {
            root = root->next;
            count++;
        }
        
        return count;
    }
        
public:

    TreeNode* helper(ListNode** head, int n) {
        if (n <= 0)  return nullptr;
        
        struct TreeNode * ptrL =  helper(head, n/2);
        struct TreeNode * root =  new TreeNode((*head)->val); *head = (*head)->next;
        struct TreeNode * ptrR =  helper(head, n - n/2 - 1);        
        
        root->left  = ptrL;
        root->right = ptrR;
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode * head) {
        if (!head)  return nullptr;
        
        int N = getLength(head);
        
        return helper(&head, N);
    }
};