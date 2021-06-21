
/*To make a string valid,
we can add some ( on the left,
and add some ) on the right.
We need to find the number of each.


Explanation:
left records the number of ( we need to add on the left of S.
right records the number of ) we need to add on the right of S,
which equals to the number of current opened parentheses.


Loop char c in the string S:
if (c == '('), we increment right,
if (c == ')'), we decrement right.
When right is already 0, we increment left
Return left + right in the end

*/


 int minAddToMakeValid(string S) {
        int left = 0, right = 0;
        for (char c : S)
            if (c == '(')
                right++;
            else if (right > 0)
                right--;
            else
                left++;
        return left + right;
    }


    class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        for ( auto c : S) {
            if ( c == '(') {
                st.push(c);
            }else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }else {
                    st.push(')');
                }
            }
        }
        
        return st.size();
        
    }
};