#include <iostream>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// post order processing of the tree.



void deleteBinaryTree(Node* &root) {
    if ( !root) return;

    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);


    delete root;
    root = nullptr;
}

// Iterative function to delete a given binary tree
void deleteBinaryTree(Node* &root)
{
    // empty tree
    if (root == nullptr) {
        return;
    }
 
    // create an empty queue and enqueue the root node
    queue<Node*> queue;
    queue.push(root);
 
    Node *front = nullptr;
 
    // loop till queue is empty
    while (!queue.empty())
    {
        // delete each node in the queue one by one after pushing their
        // non-empty left and right child to the queue
        front = queue.front();
        queue.pop();
 
        if (front->left) {
            queue.push(front->left);
        }
 
        if (front->right) {
            queue.push(front->right);
        }
 
        // it is important to delete the front node ONLY after enqueuing its children
        delete front;
    }
 
    // set root as null before returning
    root = nullptr;
}


int main()
{
    Node* root = nullptr;
 
    root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
 
    // delete the entire tree
    deleteBinaryTree(root);
 
    if (root == nullptr) {
        cout << "Tree Successfully Deleted";
    }
 
    return 0;
}