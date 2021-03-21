/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

*/

#include "header.hpp"

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int qsize = q.size();
            Node *prev = nullptr;
            Node *cur;

            while (qsize--)
            {

                cur = q.front();
                q.pop();

                if (prev)
                    prev->next = cur;

                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                prev = cur;
            }
        }

        return root;
    }
};

class SolutionRecursive {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        Node *cur = root, *dummy = new Node(0, NULL, NULL, NULL);
        for (Node* pre = dummy; cur; cur = cur -> next) {
            if (cur -> left) {
                pre -> next = cur -> left;
                pre = pre -> next;
            }
            if (cur -> right) {
                pre -> next = cur -> right;
                pre = pre -> next;
            }
        }
        connect(dummy -> next);
        dummy -> next = NULL;
        delete dummy;
        return root;
    }
};

