//
//  lc_590_nary_postorder_traversal.cpp
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
#include "header.hpp"
using namespace std;

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if ( !root) return result;
        stack<TreeNode*> st;
        st.push(root);
        while ( !st.empty()) {
            auto curr = st.top(); st.pop();
            result.insert(result.begin(), curr->val);
            for ( auto &c : curr->children) {
                st.push(c);
            }
        }
        
        return result;
        
    }
};

#endif
