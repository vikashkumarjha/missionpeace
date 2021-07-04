/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    //rule:  right->val represent child size;  root->left represent all it's child
    
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        return helpEncode(root).first;
    }
    
    //return the {head,tail}
    pair<TreeNode*, TreeNode*> helpEncode(Node* root){
        if(!root) return {nullptr, nullptr};        
        auto head = new TreeNode(root->val);
        head->right = new TreeNode(root->children.size());
        auto tail = head;
        for(auto p:root->children){
            auto pr = helpEncode(p);
            tail->left = pr.first;
            tail = pr.second;
        }
        return {head, tail};
    }

    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        return helpDecode(root).first;
    }

    //return N-ary root, and next TreeNode
    pair<Node*, TreeNode*> helpDecode(TreeNode* head){
        if(!head) return {nullptr, nullptr};
        auto root = new Node(head->val);
        auto next = head->left;
        for(int i=0;i<head->right->val;i++){
            auto pr = helpDecode(next);
            root->children.push_back(pr.first);
            next = pr.second;
        }
        return {root, next};
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
//
Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. Similarly, a binary tree is a rooted tree in which each node has no more than 2 children. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded to the original N-nary tree structure.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See following example).
