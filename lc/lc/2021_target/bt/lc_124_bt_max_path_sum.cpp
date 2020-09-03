/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes 
from some starting node to any node in the tree along the 
parent-child connections. The path must contain at least one node 
and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6


Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

*/

#include<iostream>
#include <vector>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x) , left(nullptr), right(nullptr){}
};

class Solution {
private:
	int result = INT_MIN;

	int max_gain(TreeNode *root){
		if ( root == nullptr)
			return 0;

		int left_gain = std::max(max_gain(root->left), 0);
		int right_gain = std::max(max_gain(root->right), 0);

		int curr_path_sum = root->val + left_gain  + right_gain;
		result = std::max(result , curr_path_sum);
        // the max gain if we continue the same path for recursion
		return  root->val + std::max(left_gain, right_gain);

	}

public:
    int maxPathSum(TreeNode* root) {

        max_gain(root);
        return result;
    }
};

public:
    int maxPathSum(TreeNode* root) {
       int result = INT_MIN;
       if ( !root) return 0;
       helper(root, result);
       return result;
    }
};


int main() {
    Solution s;
}
