/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

*/




#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <sstream>
#include <climits>
#include <cmath>
#include <map>

using namespace std; 


class Solution {
    struct TreeNode{
        int val;
        int sum;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x, int y) : val(x), sum(y) , left(nullptr), right(nullptr) {}
    };
    public:

        vector<int> countSmaller(vector<int> &nums) {
            TreeNode *root = nullptr;
            vector<int> res(nums.size());
            for (  int i = nums.size() - 1; i >= 0 ; i--) {
                root = buildTree(root, i, nums[i], 0, res);
            }
        }

        TreeNode *buildTree(TreeNode *root, int idx, int val, int count, vector<int> &res) {
            if (!root) {
                root = new TreeNode(val, 1);
                res[idx] = count;
                return root;
            }

            if ( val > root->val) {
                root->right = buildTree(root->right, idx, val , count + root->sum, res);
            }else {
                root->sum++;
                root->left = buildTree(root->left, idx, val, count, res);
            }

            return root;
        }



}