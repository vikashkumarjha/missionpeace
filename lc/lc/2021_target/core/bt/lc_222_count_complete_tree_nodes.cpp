class Solution {

public:

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

};

int getLeftHeight(TreeNode* root) {
    int height = 0;
    while(root) {
        root = root->left;
        height++;
    }
    return height;
}

int countNodes(TreeNode* root) {
    if(!root) return 0;

    int left_height = getLeftHeight(root->left);
    int right_height = getLeftHeight(root->right);

    if(left_height == right_height)
        return pow(2, left_height) + countNodes(root->right);

    return pow(2, right_height) + countNodes(root->left);
}
