// preorder

class SolutionPreOrder {
public:
    void preHelper(TreeNode *root, vector<int> &res) {
        if (!root) return;
        res.push_back(root->val);
        preHelper(root->left, res);
        preHelper(root->right, res);
    }
    
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        preHelper(root, res);
        return res;
        
    }
};

class SolutionPreOrderIterative {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto x = st.top(); st.pop();
            res.push_back(x->val);
            if ( x->right) {
                st.push(x->right);
            }
            if (x->left) {
                st.push(x->left);
            }
            
        }
        
        return res;
        
    }
};


// postorder

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        TreeNode *prev = nullptr;
        
        while ( root || !st.empty()) {
            while ( root) {
                st.push(root);
                root = root->left;
            }
            TreeNode *curr = st.top();
            //process the right subtree
            if (curr->right && prev != curr->right) {
                root = curr->right;
            }
            else {
                res.push_back(curr->val);
                prev = curr;
                st.pop();
            }
            
        }
        return res;
        
    }
};


// An iterative function to do post order
// traversal of a given binary tree
void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;
  
    // Create two stacks
    stack<Node *> s1, s2;
  
    // push root to first stack
    s1.push(root);
    Node* node;
  
    // Run while first stack is not empty
    while (!s1.empty()) {
        // Pop an item from s1 and push it to s2
        node = s1.top();
        s1.pop();
        s2.push(node);
  
        // Push left and right children
        // of removed item to s1
        if (node->left)
            s1.push(node->left);
        if (node->right)
            s1.push(node->right);
    }
  
    // Print all elements of second stack
    while (!s2.empty()) {
        node = s2.top();
        s2.pop();
        cout << node->data << " ";
    }
}

//Inorder


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        stack<TreeNode*> st;
        TreeNode *curr = root;
        vector<int> res;
        
        while (!st.empty() || curr) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top(); st.pop();
            res.push_back(curr->val);
            
            if ( curr->right) {
              curr = curr->right;
            }else {
                curr = nullptr;
            }
            
        }
        
        return res;
        
        
    }
};