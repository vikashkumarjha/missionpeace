
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Codec {
public:

    void serialize_helper(TreeNode *root, stringstream &ss) {
        if (!root) {
            ss << "# ";
            return;
        }
        ss << root->val;
        ss << ' ';
        serialize_helper(root->left, ss);
        serialize_helper(root->right, ss);
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        stringstream ss;
        serialize_helper(root, ss);
        
        cout << "\n Serialized output" << ss.str();
        return ss.str();
        
    }
    
    
    TreeNode *deserialize_helper(stringstream &ss) {
        string token;
        ss >> token;
        if ( token == "#") return nullptr;
        
        TreeNode *root = new TreeNode(stoi(token));
        root->left = deserialize_helper(ss);
        root->right = deserialize_helper(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        stringstream ss(data);
        TreeNode *root = deserialize_helper(ss);
        return root;
        
        
    }
};
