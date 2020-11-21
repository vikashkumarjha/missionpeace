//
//  lc_206_reverse_linked_list.cpp
//  lc
//
//  Created by vikash kumar jha on 2/29/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#if 0
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev  = nullptr;
        ListNode *next;
        ListNode *curr = head;
        
        while ( curr ) {
            next = curr->next;
            curr->next = prev;
            curr = prev;
            prev = curr;
            
        }
        
        return prev;
        
    }
};


ListNode* reverseList(ListNode* head) {
 
    if ( !head || !head->next) {
        return head;
    }
    
    ListNode* curr = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    
    return curr;
    
    
    
    
}


#endif
