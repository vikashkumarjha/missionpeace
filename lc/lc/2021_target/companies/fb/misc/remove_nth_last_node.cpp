//
//  remove_nth_last_node.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//
#if 0
#include <stdio.h>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if ( n <= 0  ) return head;
        ListNode *ref = head;
        ListNode *main = head;
        int count = 0;
        if ( head )
        {
            while ( count < n)
            {
                if ( ref == nullptr )
                {
                    return head;
                }
                ref = ref->next;
                ++count;
            }
                 
        }
        ListNode *prev =nullptr;
        while ( ref  && main )
        {
            prev  = main;
            main = main->next;
            ref = ref->next;
        }
        // at this point we can...
        if ( prev )
        {
            prev->next = main->next;
            delete main;
            return head;
        
        }
        else
        {
            if ( main == head )
            {
                head = main->next;
            }
            else
            {
                head = nullptr;
            }
            delete main;
            return head;;
        }
       
        
    }
};
#endif
