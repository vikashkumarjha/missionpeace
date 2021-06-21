class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> isVisited;
        ListNode *curr = head;
        while ( curr) {
            if ( isVisited.count(curr)) {
                return true;
            }
            isVisited.insert(curr);
            curr = curr->next;
            
        }
        
        return false;
        
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while ( fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if ( slow == fast)
                return true;
        }
        return false;
        
    }
};