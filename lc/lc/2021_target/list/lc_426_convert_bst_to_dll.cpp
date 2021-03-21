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

    Node(int _val, Node*
            _left, Node* _right) {
        val = _val;
        left =
            _left;
        right
            =
            _right;
    }
};

//key points to describe

class Solution {
public:
    Node *first = nullptr;
    Node *last = nullptr;
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        helper(root->left);
        if ( last) {
            //// link the previous node (last)
            // with the current one (node)
            last->right = node;
            node->left = last;
        }else {
            first = node;
        }
        last = node;
        helper(node->right);
    }

    Node* treeToDoublyList(Node* root) {
        if ( !root) return root;
        helper(root);
        last->right = first;
        first->left = last;
        return first;
    }
};
