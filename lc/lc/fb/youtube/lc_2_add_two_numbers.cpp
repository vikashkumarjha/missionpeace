class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        int carry = 0;
        while ( l1 || l2 ) {
            int x = ( l1 ) ? l1->val : 0;
            int y = ( l2) ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            int nodeVal = sum % 10;
            tail->next = new ListNode(nodeVal);
            tail = tail->next;
            if ( l1 ) l1 = l1->next;
            if ( l2) l2 = l2->next;
        }

        if ( carry ) {
            tail->next = new ListNode(carry);
        }

        return dummy.next;

    }
};
