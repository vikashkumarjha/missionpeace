/*
Given the root of a binary tree, construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.


Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originallay it needs to be "1(2(4)())(3()())", 
but you need to omit all the unnecessary empty parenthesis pairs. 
And it will be "1(2(4))(3)"

*/
class Solution {
public:
    
    void helper(TreeNode* root, string &res) {
        if (!root) return;
        
        res += to_string(root->val);
        
        if (root->left) {
            res += "(";
            helper(root->left, res);
            res += ")"; 
            
        }else if (root->right) {
            res += "()";
        }
        
        if (root->right) {
            res += "(";
            helper(root->right, res);
            res += ")"; 
        }
        
       
    }
    
    
    string tree2str(TreeNode* root) {
        if (!root) return "";
        string res;
        helper(root, res);
        return res;
    }
};