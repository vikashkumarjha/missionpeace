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