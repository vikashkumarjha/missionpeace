/*
 * Given the head of a sorted linked list, delete all nodes that have duplicate
 * numbers, leaving only distinct numbers from the original list. Return the
 * linked list sorted as well.
 * */

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
class Solution {
public:
    // Here we have completly removed,  All repeated elements in frontUniqL

    ListNode *deleteDuplicates(ListNode *head) {
        ListNode * dummy = new ListNode(INT_MIN);
        dummy->next = head;

        ListNode *prev = dummy;
        ListNode *curr = head;
        bool duplicate = false;

        while(curr) {
            if(curr->next && curr->val == curr->next->val)
            {
                // Remove repeated occurnace of Node in LinkList
                ListNode * tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;

                duplicate = true;
            }
            else if(duplicate)
            {
                // Here we are deleting the First Occurance of Repeated Node.
                prev->next = curr->next;
                delete curr;

                curr = prev->next;
                duplicate = false;
            }
            else
            {
                // Here we handle Normal Flow
                prev = curr;
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;

        return head;
    }
};


