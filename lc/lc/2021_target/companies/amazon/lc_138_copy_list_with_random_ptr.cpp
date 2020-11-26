
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


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

// Approach 
// add an ajacent node, populate random  then seperate

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if ( !head) return nullptr;
        Node * curr = head;
        while ( curr ) {
            auto nxt = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = nxt;
            curr = nxt;
        }

        curr = head;

        while ( curr ) {
            if ( curr->next) {
                curr->next->random = (curr->random) ? curr->random->next : nullptr;
            }
            curr = (curr->next) ? curr->next->next : nullptr;
        }


        Node *org = head;
        Node *clone = org->next;
        Node *res = clone;

        while ( org && clone) {
            org->next = ( org->next) ? org->next->next : nullptr;
            clone->next = (clone->next) ? clone->next->next : nullptr;
            org = org->next;
            clone = clone->next;
        }

        return res;

        
    }
};
 struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        
        RandomListNode *origCurr = head;
        RandomListNode *cloneCurr = NULL;
 
        std::unordered_map<RandomListNode*, RandomListNode*> mymap;
 
        while (origCurr != NULL)
        {
            cloneCurr = new RandomListNode(origCurr->label);
            mymap[origCurr] = cloneCurr;
            origCurr = origCurr->next;
        }
 
        origCurr = head;
 
        while (origCurr != NULL)
        {
            cloneCurr = mymap[origCurr];
            cloneCurr->next = mymap[origCurr->next];
            cloneCurr->random = mymap[origCurr->random];
            origCurr = origCurr->next;
        }
 
       
         return (mymap[head]);
        
        
    }
};