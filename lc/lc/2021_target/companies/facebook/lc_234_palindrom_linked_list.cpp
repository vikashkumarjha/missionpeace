/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/************************************************************************

1. Push All the elements inside Stack and count number of elements in list.
2. Pop element by element from Stack, till counter for Halfway Mark is there.
   . Compare List element and stack top element

*************************************************************************/

class Solution {
private:
    stack<int> s;
    
    public:
    bool isPalindrome(ListNode* head) {
        ListNode * curr = head;
        unsigned int count = 0;
        
        while(curr) {
            s.push(curr->val);
            curr = curr->next;
            count++;
        }
        
        count = count/2;
        curr  = head;
        
        while(count){
            int value = s.top(); s.pop();
            if (value !=  curr->val)
                return false;
            
            curr = curr->next;
            count--;
        }
        
        return true;
    }
};