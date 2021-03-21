/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if ( !head)
            return head;
        ListNode* result = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while ( m > 1){
            prev = curr;
            curr = curr->next;
            m--;
            n--;
        }
        
       // The two pointers that will fix the final connections.
        ListNode *con = prev;
        ListNode* tail = curr;
        ListNode *third = nullptr;
        while ( n > 0){
            third = curr->next;
            curr->next = prev;
            prev = curr;
            curr = third;
            n--;
        }
        if (con) {
            con->next = prev;
        } else {
            result = prev;
        }
        tail->next = curr;
        return result;
        
        
        
        
    }
};




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* left;
    bool stop;

    void helper(ListNode* right, int m , int n){
        if ( n == 1)
            return;
        
        right = right->next;
        if ( m > 1){
            left = left->next;
        }
        helper(right, m - 1, n - 1);
        
        // In case both the pointers cross each other or become equal, we
        // stop i.e. don't swap data any further. We are done reversing at this
        // point.
        if ( left == right || right->next == left)
            stop = true;
        if ( !stop){
            std::swap(left->val, right->val);
            // Move left one step to the right.
            // The right pointer moves one step back via backtracking.
            left = left->next;
        }
    }
    
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      left = head;
      stop = false;
      helper(head, m , n);
      return head;
        
    }
};



class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    
    ListNode dummyNode(0);    
        
    ListNode *dummy = &dummyNode, *prev;
    
    dummy->next = head;
    prev = dummy;
        
    for (int i = 0; i < m-1; i++)
        prev = prev->next;
        
    ListNode *reversed = prev->next, *cur;
    cur = reversed;
    
    ListNode *end = NULL;
    for (int i = 0; i < n-m+1; i++) {
        ListNode *nxt = cur->next;
        cur->next = end;
        end = cur;
        cur = nxt;
    }
    reversed->next = cur;
    prev->next = end;
        
    return dummyNode.next;
        
    }
};