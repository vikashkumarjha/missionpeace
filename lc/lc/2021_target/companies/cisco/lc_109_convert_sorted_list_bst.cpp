


TreeNode* helper(ListNode **head, int n)
{
    if ( n <= 0)
        return nullptr;

    TreeNode *ptrL = helper(head, n/2);
    TreeNode *root = new TreeNode((*head)->val); *head = (*head)->next;
    TreeNode *ptrR = helper(head, n - n/2 - 1);

    return root;
}


TreeNode * sortedListToBst(ListNode *head)
{
    if (!head)
        return nullptr;

    int n = getLength(head);
    return helper(&head, n);


}
