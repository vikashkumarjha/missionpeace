/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



 Example 1:

 Input: lists = [[1,4,5],[1,3,4],[2,6]]
 Output: [1,1,2,3,4,4,5,6]
 Explanation: The linked-lists are:
 [
   1->4->5,
     1->3->4,
       2->6
       ]
       merging them into one sorted list:
       1->1->2->3->4->4->5->6
       Example 2:

       Input: lists = []
       Output: []
       Example 3:

       Input: lists = [[]]
       Output: []

*/






struct ListNode {
    int val;
    ListNode next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode next) : val(x), next(next) {}
};





struct cmp {
    bool operator() (ListNode* a, ListNode *b) {
        return a->val > b->val;
    }
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for ( auto l : lists)
        {
            if ( l)
                pq.push(l);
        }
        if (pq.size() == 0 ) return nullptr;

        ListNode dummy(-1);
        ListNode *tail = &dummy;

        while ( !pq.empty()) {
            auto curr = pq.top(); pq.pop();
            tail->next = curr;
            if ( curr->next) {
                pq.push(curr->next);
            }
            tail = tail->next;
        }

        return dummy.next;
    }
};
