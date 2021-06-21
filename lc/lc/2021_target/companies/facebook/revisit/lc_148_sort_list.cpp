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
    ListNode* sortList(ListNode* head) {
	if ( !head || !head->next){
		return head;
	}

	//split the node into two list using two ptr...
	ListNode *slow = head;
	ListNode *fast = head->next;

	while ( fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode *firstHalf = head;
	ListNode *secondHalf = slow->next;
	slow->next = nullptr;

	return merge(sortList(firstHalf), sortList(secondHalf));


}


ListNode* merge(ListNode* l, ListNode* r) {
	if ( !l || !r){
		return l ? l : r;
	}

	if (l->val <= r->val){
		l->next = merge(l->next, r);
		return l;
	}else {
		r->next = merge(l, r->next);
		return r;
	}
}

};