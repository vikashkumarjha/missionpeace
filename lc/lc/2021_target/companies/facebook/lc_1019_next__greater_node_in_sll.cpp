class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums; 
        
        
        ListNode* curr = head;
        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        
        int N = nums.size();
        vector<int> res(N, 0); // 0 0 0
        stack<int> st; // used for index 
        
        for (int i = N - 1; i >= 0; i--) {
            //remove all elements which are less current element.
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            // if the stack is not empty then on the stack is candidate.
            if (!st.empty()) {
                res[i] = nums[st.top()];
            }
            st.push(i);
        }
        
        return res;
    }
};