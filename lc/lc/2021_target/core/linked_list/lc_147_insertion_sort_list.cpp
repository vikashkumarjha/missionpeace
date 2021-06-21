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


// keep inserting into dummy which sorted list at correct place.
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode * dummyHead = new ListNode(INT_MIN);
        ListNode * current = head;

        while (current != nullptr) {
            // Here we are processing the Current Element and Saving the Next Element Node to be processed
            ListNode * next = current->next;
            ListNode * sortListCur = dummyHead;

            while(sortListCur->next != nullptr && sortListCur->next->val < current->val) {
                sortListCur = sortListCur->next;
            }

            current->next = sortListCur->next;
            sortListCur->next = current;

            current = next;
        }

        return dummyHead->next;
    }
};
