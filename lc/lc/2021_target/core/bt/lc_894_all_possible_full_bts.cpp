/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//
// Consider N = 5
        // 0(root), 1, 2, 3, 4
        // {{1}, {2,3,4}}, {{1,2}, {3,4}}, {{1,2,3}, {4}}

/*

I will detail the methodology used to arrive to the Bottom Up DP solution.
The journey begins with identifying the recurrence relation.

Starting Thought
Use recurrence to construct a FBT for every node. A node can either have 0 children or 2 children.
Whenever the total nodes reach the target value we do a deep copy of the tree from root in the result array.
I will not go into detailed recurrence relation for this as I did not end up using this approach.

Final Recurrence Relation
The starting thought faced a challenge of making the parent node point to its left child or right child. Also it required some sort of deep copy.
A better approach is to instead of thinking of this problem per node we think of it in subtrees. If every recurrance returned all possible subtrees in a vector then managing the left and right pointers becomes easy. Also since the return value of this recurrance relation is an array no deep copy is required.
Here is the recurrence relation:

f(n)    =   []  if  n   is  0
        =   [node]  if  n   is  1
    
        =   Ɐ i = 1 to n - 1
                left[] = f(i)
                right[] = f(n - 1 - i)
                Ɐ l = 0 to left.size()
                    Ɐ r = 0 to right.size()
                        root = new node
                        node->left = left[l]
                        node->right = right[r]
                        append root to the result array
            result [root1, root2, root3...]
Recurrence with memoization
The above recurrence formulation solves the subproblems repeatedly, so keep a hash map of intermediate results.
This is implemented in allPossibleFBT_rec.

Dynamic Programming
The above recurrence relation can be converted to DP by keeping intermediate solutions for n and building the solution starting from idx = 3 to n.
As only odd numbers can have a valid solution we will only keep solutions for odd numbers, hence += 2 in the main for loop.

This is implemented in allPossibleFBT.

Code

 vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n+2);
        dp[0] = {};
        dp[1] = {new TreeNode(0)};
        for (int idx = 3; idx <= n; idx += 2) {
            for (int i = 1; i < idx - 1; i += 2) {
                vector<TreeNode*> left = dp[i];
                vector<TreeNode*> right = dp[idx - i - 1];
                for (int l = 0; l < left.size(); l++) {
                    for (int r = 0; r < right.size(); r++) {
                        TreeNode *root = new TreeNode(0);
                        root->left = left[l];
                        root->right = right[r];
                        dp[idx].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

*/

class Solution {
    unordered_map<int, vector<TreeNode*>> map;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n <= 0 || n % 2 == 0) return {};
        if (n == 1) return {new TreeNode(0)};
        if (map.find(n) != map.end()) {
            return map[n];
        }
        vector<TreeNode*> res;
        for (int i = 1; i < n-1; i += 2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            for (int l = 0; l < left.size(); l++) {
                for (int r = 0; r < right.size(); r++) {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[l];
                    root->right = right[r];
                    res.push_back(root);
                }
            }
        }
        map[n] = res;
        return res;
    }
    
};
    
   
