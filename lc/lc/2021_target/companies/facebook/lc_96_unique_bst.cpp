class Solution {
public:
    int helper(int n, unordered_map<int, int>& cache){
        if (cache.count(n)){
            return cache[n];
        }else{
            int total = 0;
            for(int i = 1; i <= n; ++i){
                total += helper(i - 1, cache) * helper(n - i, cache);
            }
            cache[n] = total;
            return total;
        }
    }
    
    int numTrees(int n) {
        unordered_map<int, int> cache;
        cache[0] = 1;
        cache[1] = 1;
        return helper(n, cache);
    }
};


int numberOfBST(int n)
{
  
    // DP to store the number of unique BST with key i
    int dp[n + 1];
    fill_n(dp, n + 1, 0);
  
    // Base case
    dp[0] = 1;
    dp[1] = 1;
  
    // fill the dp table in top-down approach.
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
  
            // n-i in right * i-1 in left
            dp[i] = dp[i] + (dp[i - j] * dp[j - 1]);
        }
    }
  
    return dp[n];
}

vector<struct node *> constructTrees(int start, int end)
{
    vector<struct node *> list;
  
    /*  if start > end   then subtree will be empty so returning NULL
        in the list */
    if (start > end)
    {
        list.push_back(NULL);
        return list;
    }
  
    /*  iterating through all values from start to end  for constructing\
        left and right subtree recursively  */
    for (int i = start; i <= end; i++)
    {
        /*  constructing left subtree   */
        vector<struct node *> leftSubtree  = constructTrees(start, i - 1);
  
        /*  constructing right subtree  */
        vector<struct node *> rightSubtree = constructTrees(i + 1, end);
  
        /*  now looping through all left and right subtrees and connecting
            them to ith root  below  */
        for (int j = 0; j < leftSubtree.size(); j++)
        {
            struct node* left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                struct node * right = rightSubtree[k];
                struct node * node = newNode(i);// making value i as root
                node->left = left;              // connect left subtree
                node->right = right;            // connect right subtree
                list.push_back(node);           // add this tree to list
            }
        }
    }
    return list;
}