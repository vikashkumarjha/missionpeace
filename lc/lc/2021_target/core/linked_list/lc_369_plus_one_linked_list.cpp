/*
Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

 

Example 1:

Input: head = [1,2,3]
Output: [1,2,4]
Example 2:

Input: head = [0]
Output: [1]

*/
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
    ListNode* plusOne(ListNode* head) {
        if (!head) nullptr;
        
        ListNode * curr = head;
        stack<ListNode *> st;
        
        while(curr){
            st.push(curr);
            curr = curr->next;
        }
        
        int carry = 1;
        ListNode * newhead = nullptr;
        
        while( !st.empty()) {
            int sum = carry + st.top()->val; st.pop();
            int sumX = sum % 10;
            carry = sum / 10;
            
            ListNode * tmp = new ListNode(sumX);
            
            if (!newhead) {
                newhead = tmp;
            } else { 
                tmp->next = newhead;
                newhead = tmp;
            }
        }
        
        if (carry){
            ListNode * tmp = new ListNode(carry); 
            tmp->next = newhead;
            newhead = tmp;
        }
        
        return newhead;
    }
};