//
//  MergeKSortedList.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/30/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>

#if 0
//defined the min heap....

struct cmp {
    bool operator() (ListNode* a, ListNode* b){
        return a->val > b->val;
    }
}



ListNode *mergeKLists(vector<ListNode *> &lists) {

    std::priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    for ( auto l : lists){
        if (l)
        pq.push(l);
    }
    
    ListNode *result = q.top();
    q.pop();
    if ( result->next ){
        pq.push(result->next);
    }
    
    ListNode *tail = result;
    
    
    while (!pq.empty()){
        auto tmp = pq.top();
        pq.pop();
        tail->next = tmp;
        tail = tail->next;
        if (tail->next){
            pq.push(tail->next);
        }
        
        
    }
    
    return result;
    
}
#endif
