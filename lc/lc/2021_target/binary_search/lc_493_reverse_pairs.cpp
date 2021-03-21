/*
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3


*/


struct Node {
    Node(int v) : val(v), count(1) , left(nullptr), right(nullptr) {}
    int val;
    int count;
    Node *left;
    Node *right;
};


//terate over ii from 00 to (size-1)(size−1) of \text{nums}nums :
//Search the existing BST for nums[i] * 2 + 1  and add the result to count
//Insert nums[i] to the BST, hence updating the count of the previous nodes

class Solution
{
public:
    Node *insert(Node *head, int val)
    {
        if (head == NULL)
            return new Node(val);
        else if (val == head->val)
            head->count++;
        else if (val < head->val)
            head->left = insert(head->left, val);
        else
        {
            head->count++;
            head->right = insert(head->right, val);
        }
        return head;
    }
    int search(Node *head, long long target)
    {
        if (head == NULL)
            return 0;
        else if (target == head->val)
            return head->count;
        else if (target < head->val)
            return head->count + search(head->left, target);
        else
            return search(head->right, target);
    }

    int reversePairs(vector<int> &nums)
    {
        Node *root = nullptr;
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += search(root, nums[i] * 2LL + 1);
            root = insert(root, nums[i]);
        }

        return res;
    }
};