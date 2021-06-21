/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity sake, each node's value is the same as the node's index (1-indexed). 
For example, the first node with val = 1, the second node with val = 2, and so on. 
The graph is represented in the test case using an adjacency list.

Adjacency list is a collection of unordered lists used to represent a finite graph.
Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. 
You must return the copy of the given node as a reference to the cloned graph.

*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        queue<Node*> q;
        q.push(node);
        while (!q.empty())
        {
            auto curr = q.front(); q.pop();
            if ( !copies.count(curr)) {
                copies[curr] = new Node(curr->val,{});
            }
            
            for ( auto n : curr->neighbors) {
                if ( !copies.count(n)) {
                    copies[n] = new Node(n->val, {});
                    q.push(n);
                }
               
                copies[curr]->neighbors.push_back(copies[n]);
            }
            
        }
        
        return copies[node];
        
        
        
    }
private:
    unordered_map<Node*,Node*> copies;
    
};

