/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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