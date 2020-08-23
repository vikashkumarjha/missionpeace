class Solution {
public:
    Node* copyRandomList(Node* head) {
         Node* curr = head;
        while ( curr){
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }

        curr = head;
        while ( curr ){
            if ( curr->next )
                curr->next->random = curr->random ? curr->random->next : curr->random;
            curr = curr->next ? curr->next->next: curr->next;
        }
        //Now seperate it out..
        Node* orig = head;
        Node* clone = orig ? orig->next: orig; 
        Node* result = clone;
        while ( orig && clone){
            orig->next = ( orig->next) ? orig->next->next : orig->next;
            clone->next = ( clone->next ) ? clone->next->next : clone->next;
            orig = orig->next;
            clone = clone->next;
        }
        return result;
        
    }
};