/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
// Consider it like PostOrder Traversal of Tree
//   -- Recursively adjust pointers

class Solution {
public:
    Node* flatten(Node* head) {
        Node *curr = head;
        
        while (curr) {
            if (curr->child) {
                Node * currnext  = curr->next;
                Node * childNode = curr->child;

                // Here we Solve Same SubProblem and get Updated curr->child
                flatten(curr->child);
                curr->child = nullptr;
                
                Node * last = childNode;
                while (last->next) 
                    last = last->next;
            
                // Here we move child as Next node of current and make curr->child as nullptr 
                curr->next = childNode;
                childNode->prev = curr;
                
                // Here we Adjust LastNode of child-List and currnext Node 
                last->next = currnext;
                if (currnext) currnext->prev = last;
            }
            
        
            curr = curr->next;
        }
        
        return head;
    }
};