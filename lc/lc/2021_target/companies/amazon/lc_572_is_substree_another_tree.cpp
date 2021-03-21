 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    bool isSameTree(TreeNode *a, TreeNode *b) {
        if ( !a && !b) return true;
        if ( !a || !b) return false;

        return (a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right));

    }

    bool isSubtree(TreeNode* s, TreeNode* t) {

        if ( !s && !t) return true;
        if ( !s || !t) return false;

        return isSameTree(s,t) || isSameTree(s->left, t) || isSameTree(s->right, t);


        
    }
};


