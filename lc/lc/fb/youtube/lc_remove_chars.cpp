/*Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

*/


/*
i refers to the index to set next character in the output string.
j refers to the index of current iteration in the input string.
*/

string removeDuplicates(string s) {

	int i = 0;
	int N = s.length();

	int j = 0;

	for ( j; j < N; j++, i++) {
		s[i] = s[j];
		if ( i  && s[i-1] == s[i]) {
			i -= 2;

		}

	}
	return s.substr(0,i);


}



 string removeDuplicates(string S) {
        string res = "";
        for (char& c : S)
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);
        return res;
    }