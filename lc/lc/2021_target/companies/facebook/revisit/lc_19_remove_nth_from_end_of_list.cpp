class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        
        while ( n--) {
            if (!fast) return head;
            fast = fast->next;
        }
        
        while ( fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            
        }
        
        ListNode *tmp = slow->next;
        slow->next = tmp->next;
        
        delete(tmp);
        return dummy->next;
        
        
    }
};