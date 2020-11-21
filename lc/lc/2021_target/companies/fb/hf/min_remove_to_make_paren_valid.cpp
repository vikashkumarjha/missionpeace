/*
Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 

Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

*/

class Solution {
public:
   
    // Get UnMatched '(' and ')' ... Replace them with *......Remove All * at the end.
    string minRemoveToMakeValid(string str) {
 
        stack<int> s;
        for (auto i = 0; i < str.size(); ++i) {
             if (str[i] == '(')
             {
                  s.push(i);
             }
             else if (str[i] == ')')
             {
                  if (!s.empty())
                      s.pop();
                  else
                      str[i] = '*'; // Not Useful ')' brace
             }
        }
       
        // Not Useful '(' brace Index's
        while (!s.empty()) {
            str[s.top()] = '*';
            s.pop();
        }
       
        str.erase(remove(str.begin(), str.end(), '*'), str.end());
 
        return str;
    }
};