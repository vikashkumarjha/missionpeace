#include <iostream>
#include<string>
#include<sstream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};



class Codec {
public:
    string serialize(TreeNode *root) {
        ostringstream oss;
        serialize_helper(root, oss);
        return oss.str();
    }

    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize_helper(iss);
    }

private:
    void serialize_helper(TreeNode *root, ostringstream &oss) {
        if ( root) {
            oss << root->val << ' ';
            serialize_helper(root->left, oss);
            serialize_helper(root->right, oss);
        }else {
            oss << "# "; // keep a space
        }
    }

    TreeNode *deserialize_helper(istringstream  &iss) {
        string token;
        iss >> token;
        if ( token == "#") {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(token));
        root->left = deserialize_helper(iss);
        root->right = deserialize_helper(iss);
        return root;
    }
};


class Codec2 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            TreeNode* node = todo.front();
            todo.pop();
            ans += node ? to_string(node -> val) + " " : "# ";
            if (node) {
                todo.push(node -> left);
                todo.push(node -> right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        string val;
        in >> val;
        if (val == "#") {
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            TreeNode* node = todo.front();
            todo.pop();
            in >> val;
            if (val != "#") {
                node -> left = new TreeNode(stoi(val));
                todo.push(node -> left);
            }
            in >> val;
            if (val != "#") {
                node -> right = new TreeNode(stoi(val));
                todo.push(node -> right);
            }
        }
        return root;
    }
};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right= new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec *c = new Codec();
    auto s = c->serialize(root);
    std::cout << "[" << s << "]\n";

    TreeNode *t = c->deserialize(s);

    auto s2 = c->serialize(t);

    if ( s == s2) {
        std::cout << "both matches...\n";
    }else {
        std::cout << "both does not match...\n";
    }

    return 0;


}
