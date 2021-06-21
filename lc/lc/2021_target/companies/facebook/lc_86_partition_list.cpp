/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.


*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    ListNode left(0);
    ListNode right(0);
    ListNode* l = &left;
    ListNode* r = &right;

    while ( head ){
        if ( head->val < x){
            l->next = head;
            l = l->next;
        }else {
            r->next = head;
            r = r->next;
        }
        head = head->next;
    }
    l->next = right.next;
    r->next = nullptr;
    return left.next;
}
};