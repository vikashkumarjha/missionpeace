/*
 * We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.


*/

class Solution {
public:
    TreeNode * helper(string & S,int & i,int d) {
        TreeNode * root = new TreeNode(INT_MIN);

        int pos = S.find_first_of("1234567890", i);
        if (pos - i != d) return nullptr;

        i = pos;
        int start = S.find("-", i);

        root->val = stoi(S.substr(i, start - i));
        i = start;

        root->left  = helper(S, i, d + 1);
        root->right = helper(S, i, d + 1);

        return root;
    }

    TreeNode* recoverFromPreorder(string S) {
        int i = S.find("-");
        TreeNode * root = new TreeNode(stoi(S.substr(0, i)));

        root->left  = helper(S, i, 1);
        root->right = helper(S, i, 1);

        return root;
    }
};
