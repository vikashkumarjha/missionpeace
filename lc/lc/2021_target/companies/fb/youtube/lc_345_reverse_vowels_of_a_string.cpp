/*
 * Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:

Input: "hello"
Output: "holle"
Example 2:

Input: "leetcode"
Output: "leotcede"

*/

class Solution {
public:

    string reverseVowels(string s) {

        int l = 0;
        int r = s.length() - 1;

        while ( l < r){
            while ( (l < r) &&
                    ((s[l] != 'a') && (s[l] != 'e') && (s[l] != 'i')&& (s[l] != 'o')&& (s[l] != 'u')) &&
                    ((s[l] != 'A') && (s[l] != 'E') && (s[l] != 'I')&& (s[l] != 'O')&& (s[l] != 'U'))

                  ){
                l++;
            }
            while ((l < r) &&
                    ((s[r] != 'a') && (s[r] != 'e') && (s[r] != 'i') &&  (s[r] != 'o') && (s[r] != 'u')) &&
                    ((s[r] != 'A') && (s[r] != 'E') && (s[r] != 'I')&& (s[r] != 'O')&& (s[] != 'U'))

                  ){
                r--;
            }


            if ( l != r && l < r){
                std::swap(s[l], s[r]);
                l++;
                r--;
            }
        }

        return s;
    }

};
