/*
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

*/


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack<int> st1;
        std::stack<int> st2;

        while ( l1 ){
            st1.push(l1->val);
            l1 = l1->next;
        }
         while ( l2 ){
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* curr = nullptr;
        ListNode* prev = nullptr;
        while ( st1.size() || st2.size() || carry){
            int x = 0;
            int y = 0;
            if ( st1.size()){
                x = st1.top();
                st1.pop();
            }
            if ( st2.size()){
                y = st2.top();
                st2.pop();
            }
            // append at beginning
            int nodeVal = ( x + y + carry ) % 10;
            carry = ( x + y + carry)/ 10;
            prev = new ListNode(nodeVal);
            prev->next = curr;
            curr = prev;
        }
        return curr;
    }
};

