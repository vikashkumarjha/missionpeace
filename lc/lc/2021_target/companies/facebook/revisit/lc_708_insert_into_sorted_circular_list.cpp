/*
Given a node from a Circular Linked List which is sorted in ascending order, write a function to insert a value insertVal into the list such that it remains a sorted circular list. The given node can be a reference to any single node in the list, and may not be necessarily the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., given node is null), you should create a new single circular list and return the reference to that single node. Otherwise, you should return the original given node.

 

Example 1:


 
Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion,
 the list should look like this, and we should still return node 3.

 

1->3->5->7->9



case 2.1 insert 10
    curr = 9 
    next = 1;


case 2.2 insert 0
if (currVal > nextVal && (insertVal >= currVal || insertVal <= nextVal))



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