/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


Test case format:

For simplicity sake, each node's value is the same as the node's index (1-indexed). For example, the first node with val = 1, the second node with val = 2, and so on. The graph is represented in the test case using an adjacency list.

Adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*,Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if ( !root) return nullptr;
        Node *clone = new Node(root->val, {});
        copies[node] = clone;
        queue<Node*> q;
        q.push(root);
        while ( !q.empty()) {
            auto curr = q.front(); q.pop();
            for ( Node *neigh : curr->neighbors) {
                if ( copies.find(neigh) == copies.end()) {
                    copies[neigh] = new Node(neigh->val, {});
                    q.push(neigh);
                }
                copies[curr]->neighbors.push_back(copies[neigh]);
            }
        }
        return clone;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                copies[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};