/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if ( !root) return root;
                std::queue<Node*> curr;
                std::queue<Node*> next;
                curr.push(root);
                while ( !curr.empty())
                {
                        Node* node = curr.front();
                        curr.pop();
                        node->next = curr.empty() ? nullptr : curr.front();
                        if ( node->left)
                                next.push(node->left);

                        if ( node->right)
                                next.push(node->right);


                        if ( curr.empty())
                        std::swap(curr,next);
                }
                return root;
        
    }
};
