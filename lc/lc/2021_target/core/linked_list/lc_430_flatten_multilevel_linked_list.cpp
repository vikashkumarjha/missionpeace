class Solution {
public:
    Node* flatten(Node* head) {
        if (head==NULL)  return head;
        Node* currentNode=head;
        while (currentNode) {            
            if (currentNode->child) { //if currentNode has a child
                Node* presentNext=currentNode->next; //setting presentNext as our currentNode's next, doing this so that we can connect the child linkedlist's end to this
                currentNode->next=currentNode->child; //setting out currentNode's next as the child :D
                currentNode->next->prev=currentNode; //since issa doubly linkedlist, gotta take care of the prev nodes and setting our currentnode->next (which is child)'s prev as currentnode
                
                currentNode->child=NULL; //removing the existence of child node since we gotta flatten
                Node*temp=currentNode->next; //now we use temp to iterate to the end of the child node 
                
    			while (temp->next) temp = temp->next;
			    temp->next = presentNext; //we are setting the end of the child node to be original currentNode's next 
                
                if (presentNext) presentNext->prev=temp; //checking that presentNext is existing (we are not at the end of the list in which case we won't need a prev node)
                
            }
            currentNode=currentNode->next; //to repeat for all the nodes 
        }
        return head;
    }
  
};