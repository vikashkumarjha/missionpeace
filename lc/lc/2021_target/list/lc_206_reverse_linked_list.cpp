/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// recursive solution.
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if ( !head || !head->next) {
            return head;
        }
        ListNode *curr = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return curr;
    }
};

//iterative solution

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if ( !head || !head->next) {
            return head;
        }
        ListNode *curr = head;
        ListNode *result= nullptr;
        ListNode *next;
        while ( curr ) {
            next = curr->next;
            curr->next = result;
            result = curr;
            curr = next; 
        }
        return result;

    }
};

