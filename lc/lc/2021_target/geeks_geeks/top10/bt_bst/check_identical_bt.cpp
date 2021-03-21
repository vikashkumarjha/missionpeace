//check two bt is identical or not 


//recursive

#include<bits/stdc++.h> 
using namespace std; 


bool isIdentical(TreeNode *x, TreeNode *y) {
    if ( !x && !y) {
        return true;
    }

    return ( x && y ) && (x->val == y->val) && isIdentical(x->left, y->left) 
    && isIdentical(x->right, y->right);

}





// Iterative function to check if two given binary trees are identical or not
bool isIdentical(Node *x, Node *y)
{
    // if both trees are empty, return true
    if (x == nullptr && y == nullptr)
        return true;
 
    // if the first tree is empty (and the second tree is non-empty), return false
    if (x == nullptr)
        return false;
 
    // if the second tree is empty (and the first tree is non-empty), return false
    if (y == nullptr)
        return false;
 
    // create a stack to hold `Node*` pairs
    stack<pair<Node*, Node*>> stack;
    stack.push({x, y});
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // pop the top pair from the stack and process it
        Node *x = stack.top().first;
        Node *y = stack.top().second;
        stack.pop();
 
        // if the value of their root node doesn't match, return false
        if (x->key != y->key)
            return false;
 
        // if the left subtree of both `x` and `y` exists, push their addresses
        // to stack; otherwise, return false if only one left child exists
        if (x->left && y->left)
            stack.push({x->left, y->left});
        else if (x->left || y->left)
            return false;
 
        // if the right subtree of both `x` and `y` exists, push their addresses
        // to stack; otherwise, return false if only one right child exists
        if (x->right && y->right)
            stack.push({x->right, y->right});
        else if (x->right || y->right)
            return false;
    }
 
    // we reach here if both binary trees are identical
    return true;
}