/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* head = new Node(insertVal);
            head->next = head;
            return head;
        }

        Node* ret = head, *curr = head;

        while (curr->next != ret) {
            int currVal = curr->val;
            int nextVal = curr->next->val;

            if (currVal > nextVal && (insertVal >= currVal || insertVal <= nextVal))
                break;

            if (currVal <= insertVal && insertVal <= nextVal)
                break;

            curr = curr->next;
        }

        Node* nNode = new Node(insertVal, curr->next);
        curr->next = nNode;

        return ret;
    }
};
