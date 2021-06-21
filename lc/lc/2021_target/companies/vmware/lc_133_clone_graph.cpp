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
public:
    unordered_map<Node*,Node*> copies;
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        queue<Node*> q;
        q.push(node);
        copies[node] = new Node(node->val, {});
        while (!q.empty())
        {
            auto curr = q.front(); q.pop();
            for ( auto n : curr->neighbors)
            {
                if ( !copies.count(n)) {
                    copies[n] = new Node(n->val, {});
                    q.push(n);
                }
                copies[curr]->neighbors.push_back(copies[n]);
            }
            
        }
        
        return copies[node];
        
    }
};