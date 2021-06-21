/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.





Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

prev 1 
conn = 2
*/



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode dummyNode(0);    
        
    ListNode *dummy = &dummyNode, *prev;
    
    dummy->next = head;
    prev = dummy;
        
    for (int i = 0; i < m-1; i++)
        prev = prev->next;
        
    ListNode *conn = prev->next, *cur;
    cur = conn;
    cout << "\n " << cur->val;    
        
    ListNode *end = NULL;
    for (int i = 0; i < n-m+1; i++) {
        ListNode *nxt = cur->next;
        cur->next = end;
        end = cur;
        cur = nxt;
    }
    conn->next = cur;
    prev->next = end;
        
    return dummyNode.next;
        
    }
};