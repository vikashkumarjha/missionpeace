Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.


class Solution {
public:
    int minVal = -1;
    int secMin = -1;
    int findSecondMinimumValue(TreeNode* root) {

        if(root == nullptr)
            return secMin;

        if(root->val < minVal || minVal == -1)
        {
            secMin = minVal;
            minVal = root->val;
        }
        else if((root->val < secMin && root->val != minVal) || (secMin == -1 && root->val != minVal))
            secMin = root->val;

        findSecondMinimumValue(root->left);
        findSecondMinimumValue(root->right);

        return secMin;
    }
};
