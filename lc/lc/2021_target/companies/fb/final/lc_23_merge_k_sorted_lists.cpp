struct cmp {
    bool operator() (const ListNode* a , const ListNode * b) {
        return a->val > b->val;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for ( auto l : lists) {
            if ( l) {
                pq.push(l);
            }
        }
        if ( pq.size() == 0) return nullptr;
        ListNode dummy = ListNode(0);
        ListNode *tail = &dummy;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            if ( curr && curr->next) {
                pq.push(curr->next);
            }

            tail->next = curr;
            tail = tail->next;

        }
        return dummy.next;


    }
};
