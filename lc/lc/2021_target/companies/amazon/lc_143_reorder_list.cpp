/*

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findCenter(ListNode* head)
    {
        if(!head) return head;
        if(!head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        
        while(fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* newHead = NULL;
        
        while(head)
        {
            ListNode* tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
        
        return newHead;
    }
    
    void merge(ListNode* h1, ListNode* h2)
    {
        ListNode fake(0);
        ListNode* ptr = &fake;
        
        while(h1 && h2)
        {
            ptr->next = h1;
            h1 = h1->next;
            ptr = ptr->next;
            
            ptr->next = h2;
            h2 = h2->next;
            ptr = ptr->next;
        }
        
        if(h1) 
        {
            ptr->next = h1;
            ptr = ptr->next;
        }
        else if(h2) 
        {
            ptr->next = h2;
            ptr = ptr->next;
        }
        
        ptr->next = NULL;
    }
    
    void reorderList(ListNode* head) 
    {
        if(!head) return;
        
        ListNode* center =  findCenter(head);
        ListNode* head_2nd = center->next;
        center->next = NULL;
        
        head_2nd = reverse(head_2nd);
        merge(head, head_2nd);
    }
};