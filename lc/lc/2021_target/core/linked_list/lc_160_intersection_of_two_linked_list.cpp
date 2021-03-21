class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA;
        ListNode *currB = headB;
        
        while ( currA   !=  currB) {
            currA = currA ? currA->next : headB;
            currB = currB ? currB->next : headA;
            
        }
        return currA;
        
    }
};