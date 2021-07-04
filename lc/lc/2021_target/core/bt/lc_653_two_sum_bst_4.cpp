

Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.
class Solution {
public:
    void helper(TreeNode *root, vector<int> &d) {
        if ( !root) return;
        helper(root->left, d);
        d.push_back(root->val);
        helper(root->right, d);
        
    }
    
    
    bool findTarget(TreeNode* root, int k) {
        if ( !root) return false;
        vector<int> data;
        helper(root, data);
        int l = 0;
        int r = data.size() - 1;
        
        while ( l < r) {
            auto currSum = data[l] + data[r];
            if ( currSum == k) return true;
            else if ( currSum > k) {
                r--;
            }else {
                l++;
            }
        }
        return false;
        
    }

};



class BSTIterator {
    stack<TreeNode*> s;
    TreeNode* node;
    bool forward;
public:
    BSTIterator(TreeNode *root, bool forward) : node(root), forward(forward) {};
    bool hasNext() {
        return node != nullptr || !s.empty();
    }
    int next() {
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = forward ? node->left : node->right;
            }
            else {
                node = s.top();
                s.pop();
                int nextVal = node->val;
                node = forward ? node->right : node->left;
                return nextVal;
            }
        }

        return -1;  // never reach & not necessary
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        BSTIterator l(root, true);
        BSTIterator r(root, false);
        for (int i = l.next(), j = r.next(); i < j;) {
            int sum = i + j;
            if (sum == k) {
                return true;
            }
            else if (sum < k) {
                i = l.next();
            }
            else {
                j = r.next();
            }
        }
        return false;
    }
};
