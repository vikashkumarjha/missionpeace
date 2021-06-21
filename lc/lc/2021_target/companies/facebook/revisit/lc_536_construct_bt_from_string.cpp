class Solution {
private:  
    // -- Here we are Constructing Tree in Bottom Up Fashion
    
    TreeNode * helper(string & s, int & i){
        if (i == s.size()) return nullptr;
        
        // Since we donot want to Waste Time and Become helpless with counting Closing Bracket
        // --- We are following Simple Number calculation Approach 
        
        string num;
        if (s[i] == '-'){
            num.push_back(s[i]);
            i++;
        }
        
        while(i < s.size() && isdigit(s[i])){
            num.push_back(s[i]);
            i++;            
        }
        
        TreeNode * root = new TreeNode(stoi(num));
        
        // In Question its mentioned, we construct Left SubTree First, if it exsist.        
        if (s[i] == '(') {
            i++;
            root->left = helper(s, i);
            i++;
        }
        
        if (s[i] == '(') {
            i++;
            root->right = helper(s, i);
            i++;
        }
                
        return root;
    }
    public:
    
    TreeNode* str2tree(string s) {
        if (s.empty()) return nullptr;
        
        int idx = 0;
        return helper(s, idx);
    }
};