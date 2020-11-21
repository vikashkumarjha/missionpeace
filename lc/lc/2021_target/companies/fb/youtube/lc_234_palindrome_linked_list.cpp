//
//  lc_234_palindrome_linked_list.cpp
//  lc
//
//  Created by vikash kumar jha on 3/7/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//



#if 0



bool isPalindrome(ListNode* head) {
    if ( !head) return true;
    
    ListNode *slow = head;
    ListNode *fast = head;
    stack<ListNode*> st;
    
    
    while ( fast && fast->next) {
        st.push(slow);
        slow = slow->next;
        fast = fast->next->next;
        
    }
    
    if ( fast) {
        slow = slow->next;
    }
    
    while ( slow) {
        auto curr = st.top(); st.pop();
        if ( curr->val != slow->val) {
            return false;
        }
        slow = slow->next;
    }
    
    return true;
    
    
}


#endif



