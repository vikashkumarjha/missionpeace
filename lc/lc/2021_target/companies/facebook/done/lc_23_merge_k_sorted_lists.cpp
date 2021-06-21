struct cmp {
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for ( auto l : lists) {
            if (l)
                pq.push(l);
        }
        if ( pq.size() == 0) {
            return nullptr;
        }
       
        while (!pq.empty())
        {
            auto curr = pq.top(); pq.pop();
            if ( curr) {
                tail->next = curr;
                tail = tail->next;
            }
            
            if ( curr && curr->next) {
                pq.push(curr->next);
            }
            
        }
        
        return dummy.next;
        
    }
};