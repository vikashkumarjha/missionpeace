
/*
Another is to do two inorder traversals. The following are the steps to be followed. 
1) Traverse the given tree in inorder fashion and store all odd level nodes in an auxiliary array. For the above example given tree, contents of array become {h, i, b, j, k, l, m, c, n, o}
2) Reverse the array. The array now becomes {o, n, c, m, l, k, j, b, i, h}
3) Traverse the tree again inorder fashion. While traversing the tree, one by one take elements from array and store elements from an array to every odd level traversed node. 
For the above example, we traverse ‘h’ first in the above array and replace ‘h’ with ‘o’. Then we traverse ‘i’ and replace it with n. 
Following is the implementation of the above algorithm.


*/

#include<bits/stdc++.h> 
#define MAX 100 
using namespace std; 
  
// A Binary Tree node 
struct Node 
{ 
    char data; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a  
// new Binary Tree Node 
struct Node *newNode(char item) 
{ 
    struct Node *temp =  new Node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Function to store nodes of  
// alternate levels in an array 
void storeAlternate(Node *root, char arr[],  
                        int *index, int l) 
{ 
    // Base case 
    if (root == NULL) return; 
  
    // Store elements of left subtree 
    storeAlternate(root->left, arr, index, l+1); 
  
    // Store this node only if this is a odd level node 
    if (l%2 != 0) 
    { 
        arr[*index] = root->data; 
        (*index)++; 
    } 
  
    // Store elements of right subtree 
    storeAlternate(root->right, arr, index, l+1); 
} 
  
// Function to modify Binary Tree  
// (All odd level nodes are 
// updated by taking elements from  
// array in inorder fashion) 
void modifyTree(Node *root, char arr[],  
                           int *index, int l) 
{ 
    // Base case 
    if (root == NULL) return; 
  
    // Update nodes in left subtree 
    modifyTree(root->left, arr, index, l+1); 
  
    // Update this node only if this  
    // is an odd level node 
    if (l%2 != 0) 
    { 
        root->data = arr[*index]; 
        (*index)++; 
    } 
  
    // Update nodes in right subtree 
    modifyTree(root->right, arr, index, l+1); 
} 
  
// A utility function to reverse an array from index 
// 0 to n-1 
void reverse(char arr[], int n) 
{ 
    int l = 0, r = n-1; 
    while (l < r) 
    { 
        int temp = arr[l]; 
        arr[l] = arr[r]; 
        arr[r] = temp; 
        l++; r--; 
    } 
} 
  
// The main function to reverse  
// alternate nodes of a binary tree 
void reverseAlternate(struct Node *root) 
{ 
    // Create an auxiliary array to store  
    // nodes of alternate levels 
    char *arr = new char[MAX]; 
    int index = 0; 
  
    // First store nodes of alternate levels 
    storeAlternate(root, arr, &index, 0); 
  
    // Reverse the array 
    reverse(arr, index); 
  
    // Update tree by taking elements from array 
    index = 0; 
    modifyTree(root, arr, &index, 0); 
} 
  
// A utility function to print indorder traversal of a 
// binary tree 
void printInorder(struct Node *root) 
{ 
    if (root == NULL) return; 
    printInorder(root->left); 
    cout << root->data << " "; 
    printInorder(root->right); 
} 
  
// Driver Program to test above functions 
int main() 
{ 
    struct Node *root = newNode('a'); 
    root->left = newNode('b'); 
    root->right = newNode('c'); 
    root->left->left = newNode('d'); 
    root->left->right = newNode('e'); 
    root->right->left = newNode('f'); 
    root->right->right = newNode('g'); 
    root->left->left->left = newNode('h'); 
    root->left->left->right = newNode('i'); 
    root->left->right->left = newNode('j'); 
    root->left->right->right = newNode('k'); 
    root->right->left->left = newNode('l'); 
    root->right->left->right = newNode('m'); 
    root->right->right->left = newNode('n'); 
    root->right->right->right = newNode('o'); 
  
    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root); 
  
    reverseAlternate(root); 
  
    cout << "\n\nInorder Traversal of modified tree\n"; 
    printInorder(root); 
  
    return 0; 
}




 void preorder(struct Node *root1, struct Node*  
                               root2, int lvl) 
{ 
    // Base cases 
    if (root1 == NULL || root2==NULL) 
        return; 
  
    // Swap subtrees if level is even 
    if (lvl%2 == 0) 
        swap(root1->key, root2->key); 
  
    // Recur for left and right  
    // subtrees (Note : left of root1 
    // is passed and right of root2 in  
    // first call and opposite 
    // in second call. 
    preorder(root1->left, root2->right, lvl+1); 
    preorder(root1->right, root2->left, lvl+1); 
} 
  
// This function calls preorder()  
// for left and right children 
// of root 
void reverseAlternate(struct Node *root) 
{ 
   preorder(root->left, root->right, 0); 
} 
  
// Inorder traversal (used to print initial and 
// modified trees) 
void printInorder(struct Node *root) 
{ 
    if (root == NULL) 
       return; 
    printInorder(root->left); 
    cout << root->key << " "; 
    printInorder(root->right); 
} 
  
// A utility function to create a new node 
Node *newNode(int key) 
{ 
    Node *temp = new Node; 
    temp->left = temp->right = NULL; 
    temp->key = key; 
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    struct Node *root = newNode('a'); 
    root->left = newNode('b'); 
    root->right = newNode('c'); 
    root->left->left = newNode('d'); 
    root->left->right = newNode('e'); 
    root->right->left = newNode('f'); 
    root->right->right = newNode('g'); 
    root->left->left->left = newNode('h'); 
    root->left->left->right = newNode('i'); 
    root->left->right->left = newNode('j'); 
    root->left->right->right = newNode('k'); 
    root->right->left->left = newNode('l'); 
    root->right->left->right = newNode('m'); 
    root->right->right->left = newNode('n'); 
    root->right->right->right = newNode('o'); 
  
    cout << "Inorder Traversal of given tree\n"; 
    printInorder(root); 
  
    reverseAlternate(root); 
  
    cout << "\n\nInorder Traversal of modified tree\n"; 
    printInorder(root); 
    return 0; 
} 



