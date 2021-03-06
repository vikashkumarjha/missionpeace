/*
Given the head of a linked list, rotate the list to the right by k places.


*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if ( head == nullptr || head->next == nullptr || k <= 0 )
        return head;
      size_t count = 1;
      ListNode* curr = head;
      while ( curr && curr->next )
      {
        curr = curr->next;
        ++count;
      }

      int computed = k % count;
      if ( computed == 0 ) return head;
      curr->next = head;
      while ( --count >= computed )
      {
          curr = curr->next;
      }
      ListNode *newhead = curr->next;
      curr->next = nullptr;
      return newhead;
    }
};