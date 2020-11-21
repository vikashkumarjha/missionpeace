class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if ( head == nullptr || head->next == nullptr)
            return head;

        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *result = curr;
        while ( true )
        {
            ListNode* next = curr->next;
            curr->next = prev;
            if ( next == nullptr || next->next == nullptr)
            {
                prev->next = next;
                break;
            }

            prev->next = next->next;
            // update prev and next
            prev = next;
            curr = prev->next;

        }
        return result;
    }
};
