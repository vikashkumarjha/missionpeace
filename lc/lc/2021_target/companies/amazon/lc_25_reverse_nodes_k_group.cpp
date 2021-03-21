/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/


class Solution {
public:
    
    ListNode* reverse(ListNode *first, ListNode *last) {
        ListNode *prev = last;
        while (first != last) {
            ListNode *nxt = first->next;
            first->next = prev;
            prev = first;
            first = nxt;
            
        }
        return prev;
        
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
    
        ListNode* curr =  head;
        for (int i = 0; i < k; i++){
                if ( !curr)
                    return head; //list too short
                curr = curr->next;
        }

        ListNode* newHead = reverse(head, curr);
        head->next = reverseKGroup(curr,k);
        return newHead;
    }
};