// Definition for a Node.
#include "../header.hpp"


class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};



class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;


        Node *head = nullptr;
        Node *prev = nullptr;


        stack<Node*> st;

        while ( root || !st.empty()) {
            while 



        }










        
    }
};