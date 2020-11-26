/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct cmp {
    bool operator() ( ListNode *a, ListNode *b) {
        return a->val > b->val;
    } 
};


class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if ( lists.empty()) return nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for ( auto l : lists) {
            if (l){
                pq.push(l);
            }
        }
        
        if ( pq.size() == 0) return nullptr;
        
        ListNode *result = pq.top(); pq.pop();
        if ( result->next) {
            pq.push(result->next);
        }
        ListNode *tail = result;
        
        while ( !pq.empty()) {
            auto curr = pq.top(); pq.pop();
            tail->next = curr;
            if ( curr->next) {
                pq.push(curr->next);
            }
            tail = tail->next;
            
        }
        
        
        return result;
        
        
    }
};