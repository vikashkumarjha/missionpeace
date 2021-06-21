 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
         if (root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int res = 0;
        while (!q.empty())
        {
            int size = q.size();
            int begin, end;
            for (int i = 0; i < size; i++)
            {
                auto cur = q.front();
                q.pop();
                if (i == 0)
                {
                    begin = cur.second;
                }
                if (i == size-1)
                {
                    end = cur.second;
                }
                if ((cur.first)->left != nullptr)
                {
                    q.push(make_pair(cur.first->left, cur.second * 2));
                }
                if ((cur.first)->right != nullptr)
                {
                    q.push(make_pair(cur.first->right, cur.second * 2+1));
                }
            }
            res = max (res, end -begin +1);
        }
        return res;
    
        
    }
};