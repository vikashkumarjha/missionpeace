


ListNode *removeNthNodeFromEnd(ListNode *head, int n) {

    if (!head)
    return nullptr;

    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *slow = head;
    ListNOde *fast = head;


    while ( n--) {
        if (!fast) return head;
        fast = fast->next;
    }

    while ( fast && fast->next) {

        slow = slow->next;
        fast = fast->next;
    }

    ListNode *nxt = slow->next;
    slow->next = nxt->next;
    delete(nxt);

    return dummy->next;









}