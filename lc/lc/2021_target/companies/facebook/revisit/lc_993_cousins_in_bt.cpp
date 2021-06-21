class Solution {
public:
    
    unordered_map<int, pair<int,TreeNode*>> m;
    
    
    bool getDepthParent(TreeNode *root, TreeNode *parent, int depth, int x) {
        if ( !root) return false;
        
        if (root->val == x) {
            m[x] = make_pair(depth, parent);
            return true;
        }
        return getDepthParent(root->left, root, depth + 1, x) ||  getDepthParent(root->right, root, depth + 1, x);
       
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *parent = nullptr;
        int depth = 0;
        
        auto flag1 = getDepthParent(root, parent,depth,x);
        auto flag2 = getDepthParent(root,parent, depth,y);
        
        if ( flag1 && flag2) {
            if ( (m[x].first == m[y].first) && (m[x].second != m[y].second)) {
                return true;
            }
        }
        return false;
        
    }
};