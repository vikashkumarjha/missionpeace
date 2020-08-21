
struct cmp {
    bool opertor () ( const &a, const &b) {
        return a->val >  b->val;
    }
}


ListNode* mergeKLists(vector<ListNode*>& lists) {
    if ( lists.empty() ) return nullptr;

    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

    for ( auto l : lists) {
        if (l)
            pq.push(l);
    }
    ListNode *head = pq.top();
    pq.pop();
    if ( head->next) {
        pq.push(head->next);
    }

    ListNode *tail = head;
    while ( !pq.empty() ) {
        auto curr = pq.top(); pq.pop();
        if ( curr->next) {
            pq.push(curr->next);
        }
        tail->next = curr;
        tail = tail->next;
    }

    return head;

}
