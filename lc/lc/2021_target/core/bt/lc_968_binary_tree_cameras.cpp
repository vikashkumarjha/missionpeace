class Solution {
private:

    static constexpr unsigned int  NO_CAMERA  = {0};
    static constexpr unsigned int  HAS_CAMERA = {2};
    static constexpr unsigned int  NOT_NEEDED = {1};

    int count = 0;

public:
    // Here at given Node we ony can have Information : left child and right child
    //  -- Take decision on CAMERA being present or Not at left anf right subtree Root Node.

    int treeDFS(TreeNode *root) {
        if (!root)  return NOT_NEEDED;

        int l = treeDFS(root->left);
        int r = treeDFS(root->right);

        if (l == NO_CAMERA || r == NO_CAMERA) {
            count++;
            return HAS_CAMERA;
        }
        else if (l == HAS_CAMERA || r == HAS_CAMERA) {
            return NOT_NEEDED;
        }
        else {
            return NO_CAMERA;
        }
    }

    int minCameraCover(TreeNode* root) {
        if (treeDFS(root) == NO_CAMERA)
            count++;

        return count;
    }
};

