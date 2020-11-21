//
//  linked_list_detect_cycle.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#if 0
#include <iostream>


bool hasCycle(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    while ( slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        
        if ( slow == fast){
            return true;
        }
        return false;
    }
    
    
}
#endif
