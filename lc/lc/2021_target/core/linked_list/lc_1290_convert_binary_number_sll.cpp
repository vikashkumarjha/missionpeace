class Solution {
public:
    int getDecimalValue(ListNode* head) {
        if (!head) return 0;
        stack<int> st;
        int res = 0;
        ListNode *curr = head;
        while ( curr) {
            st.push(curr->val);
            curr = curr->next;
        }
        int index = 0;
        while ( !st.empty()) {
            auto x = st.top(); st.pop();
            res += pow(2,index) * x;
            index++;
        }

        return res;

    }
};
