/*
In a Preorder sequence, the leftmost element is the root of the tree. So we know ‘A’ is the root for given sequences. By searching ‘A’ in the Inorder sequence, we can find out all elements on the left side of ‘A’ is in the left subtree, and elements on right in the right subtree. So we know the below structure now. 

                 A
               /   \
             /       \
           D B E     F C
We recursively follow the above steps and get the following tree.

         A
       /   \
     /       \
    B         C
   / \        /
 /     \    /
D       E  F
Algorithm: buildTree() 
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick the next element in the next recursive call. 
2) Create a new tree node tNode with the data as the picked element. 
3) Find the picked element’s index in Inorder. Let the index be inIndex. 
4) Call buildTree for elements before inIndex and make the built tree as a left subtree of tNode. 
5) Call buildTree for elements after inIndex and make the built tree as a right subtree of tNode. 
6) return tNode.
*/


class Solution {
public:
    TreeNode *helper(vector<int> &pre, vector<int> &in, int &rootIdx, int l, int r) {
        if ( l > r) return nullptr;
        
        int rootVal = pre[rootIdx];
        
        cout << "\n The value of" << rootVal;
        int pivot = l;
        while ( in[pivot] != rootVal) pivot++;
        
        TreeNode *root = new TreeNode(rootVal);
        rootIdx++;
        root->left = helper(pre, in, rootIdx, l, pivot - 1);
        root->right = helper(pre, in, rootIdx,  pivot+1, r);
        
        return root;
      
        
    }


    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int rootIdx = 0;
        
        return helper(preorder, inorder, rootIdx, 0, n - 1);
        
        
    }
};