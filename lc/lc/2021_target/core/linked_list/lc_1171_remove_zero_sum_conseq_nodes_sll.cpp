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

//1,2,-3,3,1
/*
Because the head ListNode can be removed in the end,
I create a dummy ListNode and set it as a previous node of head.
prefix calculates the prefix sum from the first node to the current cur node.

Next step, we need an important hashmap m (no good name for it),
It takes a prefix sum as key, and the related node as the value.

Then we scan the linked list, accumulate the node's value as prefix sum.

If it's a prefix that we've never seen, we set m[prefix] = cur.
If we have seen this prefix, m[prefix] is the node we achieve this prefix sum.
We want to skip all nodes between m[prefix] and cur.next (exclusive).
So we simplely do m[prefix].next = cur.next.

*/

/****************************************************************************

The prefix sum can be stored and retrieved using a hash map. We accumulate the sum (as key), and store its node as value in the hash map. Then, when a sum occurs, we know the interval between two link nodes sum to zero. We can then re-point the previous node’s next to the next node which effectively removes the nodes between.

****************************************************************************/

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;

        map<int, ListNode*> hash;
        ListNode * curr = dummy;
        int sum = 0;

        while (curr) {
            sum += curr->val;

            if (hash.count(sum)) {
                //  when a sum occurs, we know the interval between two link nodes sum to zero.
                ListNode * start  = hash[sum]->next;
                int p = sum + start->val;

                while (p != sum) {
                    hash.erase(p);
                    start = start->next;
                    p += start->val;
                }

                // Here we are doing Pointer Patching (We have already deleted Chunk having Sum to Zero)
                hash[sum]->next = curr->next;
            }
            else
            {
                hash[sum] = curr;
            }

            curr = curr->next;
        }

        return dummy->next;
    }
};
