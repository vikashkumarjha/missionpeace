/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        Node* copy = new Node(node->val, {});
        copies[node] = copy;
        queue<Node*> todo;
        todo.push(node);
        while (!todo.empty()) {
            Node* cur = todo.front();
            todo.pop();
            for (Node* neighbor : cur->neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor-> val, {});
                    todo.push(neighbor);
                }
                //relationship mapping.
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }
        return copy;
    }
private:
    unordered_map<Node*, Node*> copies;
};
