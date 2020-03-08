//
//  lc_589_nary_preorder_traversal.cpp
//  lc
//
//  Created by vikash kumar jha on 3/7/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

#if 0
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<Node*> st;
        Node* curr=root;
        st.push(curr);
        while(!st.empty()){
            curr=st.top(); st.pop();
            res.push_back(curr->val);
            for(int i=curr->children.size()-1;i>=0;--i)
                    st.push(curr->children[i]);
        }
        return res;
    }
};

#endif
