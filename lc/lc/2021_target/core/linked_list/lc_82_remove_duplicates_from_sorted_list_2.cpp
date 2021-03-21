/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3

*/
class Solution {
public:
    // Here we have completly removed,  All repeated elements in frontUniqL
   
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * dummy = new ListNode(INT_MIN);
        dummy->next = head;
       
         ListNode *prev = dummy;
         ListNode *curr = head;
        bool duplicate = false;
       
        while(curr) {
            if(curr->next && curr->val == curr->next->val)
            {
                // Remove repeated occurnace of Node in LinkList
                ListNode * tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
               
                duplicate = true;
            }
            else if(duplicate)
            {
                // Here we are deleting the First Occurance of Repeated Node.
                prev->next = curr->next;
                delete curr;
               
                curr = prev->next;
                duplicate = false;
            }
            else
            {
                // Here we handle Normal Flow
                prev = curr;
                curr = curr->next;
            }
        }
       
        head = dummy->next;
        delete dummy;
       
        return head;
    }
};

