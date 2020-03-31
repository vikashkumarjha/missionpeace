/*
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

 

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.


*/

class Solution {
public:
    bool isLongPressedName(string s, string t) {
        int i=0,j=0;
        while(j<t.length())
        {
            if(i<s.length()&&s[i]==t[j])
            {
                i++;
                j++;
            }
            else if(i>0&&s[i-1]==t[j])
                        j++;
            else
                return false;
        }
        return i==s.length();
        
    }
};