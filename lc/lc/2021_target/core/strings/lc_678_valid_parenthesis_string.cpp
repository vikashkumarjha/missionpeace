/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True

*/


class Solution{
public:
    bool checkValidString(string s){
        return go(s);
    }
    
    bool go(const string& s, int i=0, int open=0){
        if (open < 0)
            return false;

        if (i==s.size())
            return open==0;
        
        if (s[i]=='(')
            ++open;
        
        else if (s[i]==')')
            --open;
        
        else
            return go(s,i+1,open+1) || go(s,i+1,open-1) || go(s,i+1,open);
        
        return go(s,i+1,open);
    }
};


