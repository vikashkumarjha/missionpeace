//
//  get_intersection_node.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//
#if 0
#include <stdio.h>

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
 
    ListNode *currA = headA;
    ListNode *currB = headB;
    
    while ( currA != currB){
        currA = (currA) ? currA->next : currB;
        currB = (currB) ? currB->next :currA
        
    }
    return currA;
    
}

#endif
