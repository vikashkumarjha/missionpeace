/*
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return l1;

        if (!l1 || !l2) {
            return ( l1) ? l1 : l2;
        }

        int carry = 0;
        ListNode dummy = ListNode(0);
        ListNode *tail = &dummy;

        while ( l1 || l2) {
            int x = 0;
            int y = 0;
            if ( l1) {
                x = l1->val;
                l1 = l1->next;
            }
            if ( l2) {
                y = l2->val;
                l2= l2->next;
            }
            int sum = x + y + carry;
            tail->next = new ListNode( sum % 10);
            carry = sum / 10;
            tail = tail ->next;
        }
        if ( carry) {
            tail->next = new ListNode(carry);
        }
        return dummy.next;

    }
};
