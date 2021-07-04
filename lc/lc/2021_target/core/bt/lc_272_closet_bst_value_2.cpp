class Solution {
public:
   void dfs(TreeNode* root, root, priority_queue<pair<double,int>>  &pq, double target, int k)
{
    if ( !root)
        return;
    pq.push(fabs(root->val- target), root->val);
    if ( pq.size() > k ){
        pq.pop();
    }
    dfs(root->left,pq, target, k);
    dfs(root->right,pq, target, k);

}


vector<int> closestKValues(TreeNode* root, double target, int k) {

    vector<int> result;
    priority_queue<pair<double,int>> pq;

    dfs(root, pq, target, k);

    while (!pq.empty()){
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;

}
};
