//
//  reverse_linked_list.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/31/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#if 0
#include <iostream>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseList(ListNode* head) {
    ListNode *prev = nullptr;
    ListNode *next;
    ListNode *curr = head;
    
    while ( curr ){
        next = curr;
        curr->next = prev;
        prev = curr;
        curr = next;
        
    }
    
    return prev;
    
    
    
}


ListNode* reverseList(ListNode *head){
    if ( !head || !head->next){
        return head;
    }
    
    ListNode *curr = reverseList(head->next);
    
    head->next->next = head;
    head->next = nullptr;
    return curr;
    
    
}
#endif
