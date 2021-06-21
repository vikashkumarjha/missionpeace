class Solution {
public:
    ListNode* findCenter(ListNode* head)
    {
        if(!head) return head;
        if(!head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
          
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* newHead = NULL;
        
        while(head)
        {
            ListNode* tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }
        
        return newHead;
    }
    
    void merge(ListNode* h1, ListNode* h2)
    {
        ListNode fake(0);
        ListNode* ptr = &fake;
        
        while(h1 && h2)
        {
            ptr->next = h1;
            h1 = h1->next;
            ptr = ptr->next;
            
            ptr->next = h2;
            h2 = h2->next;
            ptr = ptr->next;
        }
        
        if(h1) 
        {
            ptr->next = h1;
            ptr = ptr->next;
        }
        else if(h2) 
        {
            ptr->next = h2;
            ptr = ptr->next;
        }
        
        ptr->next = NULL;
    }
    
    void reorderList(ListNode* head) 
    {
        if(!head) return;
        
        ListNode* center =  findCenter(head);
        ListNode* head_2nd = center->next;
        center->next = NULL;
        
        head_2nd = reverse(head_2nd);
        merge(head, head_2nd);
    }
};