#include <iostream>
#include <vector>
using namespace std;

// keep stack for storing the left subtree...


class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int lower_bound = INT_MIN;

        stack<int> st;
        for ( n : preorder)
        {
            if (n < lower_bound)
                return false;
            while (!st.empty() && n > st.top())
            {
                lower_bound = st.top();
                st.pop();
            }
            st.push(n);
        }

        return true;
    }
};



// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
};
 
// Function to create a new binary tree node having a given key
Node* newNode(int key)
{
    Node* node = new Node;
    node->data = key;
    node->left = node->right = nullptr;
 
    return node;
}
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return newNode(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
 
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Recursive function to build a BST from the given sequence
Node* buildTree(vector<int> const &seq)
{
    // construct a BST by inserting keys from the given sequence
    Node* root = nullptr;
    for (int key: seq) {
        root = insert(root, key);
    }
 
    // return root node
    return root;
}
 
// Function to compare the preorder traversal of a BST with the given sequence
bool comparePreOrder(Node* root, vector<int> const &seq, int &index)
{
    // base case
    if (root == nullptr) {
        return true;
    }
 
    // return false if the next element in the given sequence doesn't match
    // with the next element in the preorder traversal of BST
    if (seq[index] != root->data) {
        return false;
    }
 
    // increment index
    index++;
 
    // compare the left and right subtrees
    return comparePreOrder(root->left, seq, index) &&
        comparePreOrder(root->right, seq, index);
}
 
// Function to check if a given sequence represents the preorder traversal of a BST
bool isBST(vector<int> const &seq)
{
    /* 1. Construct the BST from the given sequence */
 
    Node* root = buildTree(seq);
 
    /* 2. Compare the preorder traversal of BST with the given sequence */
 
    // `index` stores the index of the next unprocessed node in the preorder sequence
    int index = 0;
    return comparePreOrder(root, seq, index) && index == seq.size();
}



