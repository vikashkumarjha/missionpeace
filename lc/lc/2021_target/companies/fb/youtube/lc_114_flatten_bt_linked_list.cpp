class Solution {
private:    
    void helper(TreeNode * root, TreeNode *& head){
        if (!root)
            return ;

        helper(root->right, head);
        helper(root->left,  head);

        root->left = nullptr;
        root->right = head;
        head = root;


    }


public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        TreeNode * head = nullptr;    
        helper(root, head);

    }
};



class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left && root->right) {
                TreeNode* t = root->left;
                while (t->right)
                    t = t->right;
                t->right = root->right;
            }

            if(root->left)
                root->right = root->left;
            root->left = NULL;
            root = root->right;
        }

    }
};
