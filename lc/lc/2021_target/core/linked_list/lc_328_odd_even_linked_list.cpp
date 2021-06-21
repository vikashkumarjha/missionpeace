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

//Input: 1->2->3->4->5->NULL
//Output: 1->3->5->2->4->NULL

class Solution {
public:
    ListNode* oddEvenList( ListNode* head) {
        if ( !head || !head->next) return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = head->next;
        
        while (even && even->next) {
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
         
        }
        
        odd->next = evenHead;
        return head;
      
        
    }
};
