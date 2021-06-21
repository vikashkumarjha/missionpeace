class Solution {
private:

    int getLength(struct ListNode * root) {
        int count = 0;        
        while (root) {
            root = root->next;
            count++;
        }

        return count;
    }

public:

    TreeNode* helper(ListNode** head, int n) {
        if (n <= 0)  return nullptr;

        struct TreeNode * ptrL =  helper(head, n/2);
        struct TreeNode * root =  new TreeNode((*head)->val); *head = (*head)->next;
        struct TreeNode * ptrR =  helper(head, n - n/2 - 1);        

        root->left  = ptrL;
        root->right = ptrR;

        return root;
    }

    TreeNode* sortedListToBST(ListNode * head) {
        if (!head)  return nullptr;

        int N = getLength(head);

        return helper(&head, N);
    }
};






class Solution {
private:

    // Function to push nodes of a given doubly linked list in a vector
    void pushDDLNodes(ListNode* node, vector<ListNode*> &nodes)
    {
        while (node)
        {
            nodes.push_back(node);
            node = node->next;
        }
    }

    TreeNode* buildBalancedBST(vector<ListNode*> &nodes, int start, int end)
    {
        // base case
        if (start > end) {
            return nullptr;
        }

        // find the middle index
        int mid = (start + end) / 2;

        // The root node will be a node present at the mid-index
        TreeNode* root= new TreeNode(nodes[mid]->val);

        // recursively construct left and right subtree
        root->left = buildBalancedBST(nodes, start, mid - 1);
        root->right = buildBalancedBST(nodes, mid + 1, end);
        // return root node
        return root;
    }

    TreeNode* convertSortedDLLToBalancedBST(ListNode*& headRef)
    {
        // Push nodes of a given doubly linked list into a vector in the original order
        vector<ListNode*> nodes;
        pushDDLNodes(headRef, nodes);
        // Construct a height-balanced BST from sorted BST nodes
        return buildBalancedBST(nodes, 0, nodes.size() - 1);
    }

public:
    TreeNode* sortedListToBST(ListNode * head) {
        if (!head)  return nullptr;
        return convertSortedDLLToBalancedBST(head);
    }
};
