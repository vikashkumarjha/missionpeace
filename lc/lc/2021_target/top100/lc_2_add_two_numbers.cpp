#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

#include "../header.hpp"
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode *tail = &dummy;
        int carry = 0;
        while ( l1 || l2) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int s = (x + y + carry) % 10;
            carry = ( x + y + carry) / 10;

            tail->next = new ListNode(s);
            tail = tail->next;
            if (l1 ) l1= l1->next;
            if ( l2) l2 = l2->next;
        }
        if ( carry ){
            tail->next = new ListNode(carry);
        }
        return dummy.next;
        
    }
};