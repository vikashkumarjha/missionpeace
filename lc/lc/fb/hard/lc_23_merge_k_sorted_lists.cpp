#include "header.hpp"
using namespace std;


/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
public:

   struct cmp {
       bool operator() ( const ListNode *a, const ListNode *b) {
           return  a->val > b.val;
       }
   }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for ( auto l : lists) {
            pq.push(l);
        }

        if ( pq.empty()) return nullptr;

        ListNode *head = pq.top();
        pq.pop();
        if ( head->next) {
            pq.push(head->next);
        }

        ListNode *tail = head;

        while ( !pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if ( tail->next) {
                pq.push(tail->next);
            }

        }
        return head;

    }
};
