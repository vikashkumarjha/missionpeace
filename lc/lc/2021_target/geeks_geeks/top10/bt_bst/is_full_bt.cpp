// check whether a bt is full binary tree
// all nodes are having either zero or two nodes



bool isFullBt(Node *root)
{
  if (!root) return true;
  if (!root->left && !root->right)
    return true;


  if ( root->left && root->right)
    return (isFullBt(root->left) && isFullBt(root->right));

  return false;


}
