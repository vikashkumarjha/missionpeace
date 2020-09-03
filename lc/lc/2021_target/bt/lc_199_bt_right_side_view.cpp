/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

  */
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x) , left(nullptr), right(nullptr){}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto qsize = q.size();
            for (int k = 0; k < qsize; k++)
            {
                auto curr = q.front();
                q.pop();
                if (k == 0)
                {
                    result.push_back(curr->val);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
                if (curr->left)
                {
                    q.push(curr->left);
                }
            }
        }
        return result;
    }
};

class Solution2
{
private:
    void dfs(TreeNode *root, vector<int> &result, int level)
    {
        if (!root)
            return;
        if (result.size() == level)
        {
            result.push_back(root->val);
        }
        dfs(root->right, result, level + 1);
        dfs(root->left, result, level + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        dfs(root, result, 0);
        return result;
    }

};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution s1;
    auto r = s1.rightSideView(root);
    std::for_each(r.begin(), r.end(), [](int x){
        cout << "[ "<< x << " ] ";
    });

    return 0;
}