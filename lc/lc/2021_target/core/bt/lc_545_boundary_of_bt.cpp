class Solution {
public:
    void getLeftBoundary(TreeNode* node, std::vector<int>& v)
{
  if ( node)
  {
    if ( node->left)
    {
      v.push_back(node->val);
      getLeftBoundary(node->left,v);
    }
    else if ( node->right)
    {
      v.push_back(node->val);
      getLeftBoundary(node->right,v);
    }
  }
}
    
void getLeaves(TreeNode* node, std::vector<int>& v)
{
  if ( node )
  {
    getLeaves(node->left,v);
    if ( !node->left && !node->right)
      v.push_back(node->val);
    getLeaves(node->right,v);
  }
}


void getRightBoundary(TreeNode* node, std::vector<int>& v)
{
  if ( node )
  {
    if ( node->right)
    {
      getRightBoundary(node->right,v);
      v.push_back(node->val);
    }
    else if ( node->left)
    {
        getRightBoundary(node->left,v);
        v.push_back(node->val);
    }
  }
}
    
    std::vector<int> boundaryOfBinaryTree(TreeNode* root) {
        std::vector<int> boundary;
        if ( !root) return boundary;
        //we will print left the subtree
         boundary.push_back(root->val);
        getLeftBoundary(root->left,boundary);
        getLeaves(root->left,boundary);
         getLeaves(root->right,boundary);
        getRightBoundary(root->right,boundary);

        return boundary;
        
    }
};
