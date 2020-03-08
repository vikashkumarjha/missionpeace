//
//  merge_sorted_lists.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/30/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <stdio.h>

#if 0
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    ListNode dummy;
    ListNode *tail = &dummy;
    
    while ( l1 && l2){
        if ( l1->val <= l2->val ){
            tail->next = l1;
            l1 = l1->next;
        }else {
            tail->next = l2;
            l2 = l2->next;
        }
        
        tail = tail->next;
      
    }
    
    tail->next = (l1) ? l1 : l2;
    
    return dummy.next;
    
    
}
#endif
