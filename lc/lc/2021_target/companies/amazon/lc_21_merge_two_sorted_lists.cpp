class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( !l1) return l2;
        if ( !l2) return l1;
        
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        
        while ( l1 && l2) {
            if ( l1->val > l2->val) {
                tail->next = l2;
                l2 = l2->next;
            }else {
                tail->next = l1;
                l1 = l1->next;
            }
            tail = tail->next;    
            
        }
        
        tail->next = ( l1) ? l1 : l2;
        
        return dummy.next;
        
        
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( !l1) return l2;
        if ( !l2) return l1;
        
        if ( l1->val > l2->val){
             l2->next = mergeTwoLists(l1, l2->next);
             return l2;
        }
        else {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;   
        }
       
    }
};