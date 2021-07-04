vector<int> pp, pq;
bool getPath(TreeNode* r, int val, vector<int>&path) {
    if (r != nullptr) {
        path.push_back(r->val);
        if (r->val == val || getPath(r->left, val, path) || getPath(r->right, val, path))
            return true;
        path.pop_back();
    }
    return false;
}
int findDistance(TreeNode* r, int p, int q) {
    auto _ = getPath(r, p, pp), __ =  getPath(r, q, pq);
    for (auto i = 0; i < min(pp.size(), pq.size()); ++i) {
        if (pp[i] != pq[i])
            return pp.size() + pq.size() - i * 2;
    }
    return abs((int)pp.size() - (int)pq.size());
}
