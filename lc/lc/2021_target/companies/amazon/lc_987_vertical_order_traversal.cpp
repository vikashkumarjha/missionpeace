/*
Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the vertical line touches some nodes, we report the values of the nodes in order from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will have a list of values of nodes.

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    map<int, map<int, set<int>>> m;
    
public:
    void treeDFS(TreeNode * root, int x, int y){
        if (!root)
            return;
    
        m[x][y].insert(root->val);

        treeDFS(root->left,  x - 1, y + 1);
        treeDFS(root->right, x + 1, y + 1);   
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        treeDFS(root, 0, 0);
        
        vector<vector<int>> result;
        
        for (const auto & iter1 : m){
            vector<int> tmp;
            for (const auto & iter2 :iter1.second)
                for (const auto & iter3 : iter2.second)
                    tmp.push_back(iter3);
            
            result.push_back(tmp);
        }
        
        return result;
        
    }
};