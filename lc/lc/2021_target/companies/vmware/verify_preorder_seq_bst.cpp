
/*
An Efficient Solution can solve this problem in O(n) time. 
The idea is to use a stack. This problem is similar to Next (or closest) Greater Element problem. Here we find the next greater element and after finding next greater, 
if we find a smaller element, then return false.
*/





class Solution {
public:
    bool verifyPreorder(vector<int>& pre) {
        stack<int> st;
        int n = pre.size();
        int root = INT_MIN;
        
        
        for ( int i = 0; i < n; i++) {
            if ( pre[i] < root) {
                return false;
            }
            
            while (!st.empty() && st.top() < pre[i]) {
                root = st.top();
                st.pop();
                
            }
            st.push(pre[i]);
            
        }
        
        return true;
        
        
    }
};
// construct bt in the preorder fashion.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
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
 
// Recursive function to build a BST from the given sequence in a preorder fashion
Node* buildTree(vector<int> const &seq, int &index, int min, int max)
{
    // Base case
    if (index == seq.size()) {
        return nullptr;
    }
 
    // Return if the next element of the given sequence is within the invalid range
    int val = seq[index];
    if (val < min || val > max) {
        return nullptr;
    }
 
    // Construct the root node and increment index
    Node* root = newNode(val);
    index++;
 
    // Since all elements in the left subtree of a BST must be less
    // than the root node's value, set range as `[min, val-1]` and recur
    root->left = buildTree(seq, index, min, val - 1);
 
    // Since all elements in the right subtree of a BST must be greater
    // than the root node's value, set range as `[val+1…max]` and recur
    root->right = buildTree(seq, index, val + 1, max);
 
    // return root node
    return root;
}
 
// Function to check if a given sequence represents the preorder traversal of a BST
bool isBST(vector<int> const &seq)
{
    /* 1. Construct the BST from the given sequence in a preorder fashion */
 
    // stores index of the next unprocessed node in the sequence
    int index = 0;
 
    // set the root node's range as [-INFINITY, INFINITY] and recur
    Node* root = buildTree(seq, index, INT_MIN, INT_MAX);
 
    /* 2. Just check if the whole sequence is traversed or not */
    return index == seq.size();
}
 
int main()
{
    vector<int> seq = { 15, 10, 8, 12, 20, 16, 25 };
 
    if (isBST(seq)) {
        cout << "Sequence represents preorder traversal of a BST";
    }
    else {
        cout << "Sequence doesn't represent preorder traversal of a BST";
    }
 
    return 0;
}


