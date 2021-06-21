/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    void serialize_helper(Node *root, stringstream &ss) {
        if (!root) {
            ss << "# ";
            return;
        }
        ss << root->val;
        ss << ' ';
        
        ss << root->children.size();
        ss << ' ';
        
        for ( auto child : root->children) {
               serialize_helper(child,  ss);
        }
        
    }
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        
        stringstream ss;
        serialize_helper(root, ss);
        
        
        return ss.str();
        
    }
    
    
    Node *deserialize_helper(stringstream &ss) {
        string token;
        ss >> token;
        if ( token == "#") return nullptr;
        
        Node *root = new Node(stoi(token));
        ss >> token;
        int numberOfChild = stoi(token);
        for ( int k = 0; k < numberOfChild; k++) {
            root->children.push_back(deserialize_helper(ss));
        }
        
        return root;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        
        stringstream ss(data);
        Node *root = deserialize_helper(ss);
        return root;
        
        
    }
};
