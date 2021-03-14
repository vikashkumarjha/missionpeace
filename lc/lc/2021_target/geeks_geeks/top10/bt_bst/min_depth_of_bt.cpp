//Given a BT find its minimum depth



int minDepth(TreeNode *root) {
    if (!root) 
        return 0;

    if (!root->left && !root->right){
        return 1;
    }    

    if (!root->left) {
        return minDepth(root->right) + 1;
    }

    if (!root->right) {
        return minDepth(root->left) + 1;
    }


    return min(minDepth(root->left), minDepth(root->right)) + 1;

}



// use level order traversal to get the min depth


int minDepth2(TreeNode *root) {

    if (!root) return 0;

    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root,1));

    while (!q.empty()) {

        auto x = q.front(); q.pop();
        int d = x.second;
        auto n = x.first;

        if ( !n->left && !n->right) {
            return d;
        }


        if (n->left) {
            q.push(make_pair(n->left, d+1));
        }


        if (n->right) {
            q.push(make_pair(n->right, d+1));
        }

    }


    return 0;

}

