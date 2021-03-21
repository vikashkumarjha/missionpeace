/*
 * Given a string S, remove the vowels 'a', 'e', 'i', 'o', and 'u' from it, and return the new string.



Example 1:

Input: "leetcodeisacommunityforcoders"
Output: "ltcdscmmntyfrcdrs"


*/


class Solution {
public:
    string removeVowels(string S) {

      char c;
      for(auto it = S.begin(); it != S.end(); ++it)
      {
        c = *it;
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
          S.erase(it--);
      }
      return S;

    }
};

class Solution {
public:
    string removeVowels(string S) {
        int i, j;
        for( i=0, j=0; j<S.size(); j++){
            if(S[j]!='a'&&S[j]!='e'&&S[j]!='i'&&S[j]!='o'&&S[j]!='u')   S[i++]=S[j];
        }
        S.erase( i, S.size()-i);
        return S;
    }
};
