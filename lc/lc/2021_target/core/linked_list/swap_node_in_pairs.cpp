/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        // if there is only one node then
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *result = curr;
        while (true)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            if (next == nullptr || next->next == nullptr)
            {
                prev->next = next;
                break;
            }
            //
            prev->next = next->next;
            //update prev and curr

            prev = next;
            curr = prev->next;
        }
        return result;
    }
};