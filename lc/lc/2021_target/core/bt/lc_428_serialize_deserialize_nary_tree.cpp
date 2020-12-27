/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree

*/
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