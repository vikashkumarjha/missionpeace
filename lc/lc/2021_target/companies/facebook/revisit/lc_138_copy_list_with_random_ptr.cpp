/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node *curr = head;
        while ( curr) {
            Node *next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        
        // initialize the curr
        curr = head;
        while ( curr ) {
            if (curr->next) {
                curr->next->random = (curr->random) ? curr->random->next : nullptr;
            }
            curr = (curr->next) ? curr->next->next : nullptr;
            
        }
        
        Node *org = head;
        Node *clone = head->next;
        
        Node *res = clone;
        while ( org && clone) {
            org->next = (org->next) ? org->next->next : nullptr;
            clone->next = (clone->next) ? clone->next->next : nullptr;
            org = org->next;
            clone = clone->next;
            
        }
        
        return res;
        
        
        
        
    }
};