/*
Given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple “croak” are mixed. Return the minimum number of different frogs to finish all the croak in the given string.

A valid "croak" means a frog is printing 5 letters ‘c’, ’r’, ’o’, ’a’, ’k’ sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of valid "croak" return -1.

 

Example 1:

Input: croakOfFrogs = "croakcroak"
Output: 1 
Explanation: One frog yelling "croak" twice.
Example 2:

Input: croakOfFrogs = "crcoakroak"
Output: 2 
Explanation: The minimum number of frogs is two. 
The first frog could yell "crcoakroak".
The second frog could yell later "crcoakroak".

*/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        
        int n = croakOfFrogs.length();
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        int ans = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (croakOfFrogs[i] == 'c') {
                c++;
                count++;
            } else if (croakOfFrogs[i] == 'r') {
                r++;
            } else if (croakOfFrogs[i] == 'o') {
                o++;
            } else if (croakOfFrogs[i] == 'a') {
                a++;
            } else if (croakOfFrogs[i] == 'k') {
                k++;
                count--;
            }
            ans = max(ans, count);
            if (c < r || r < o || o < a || a < k)
                return -1;
        }
        
        if (count == 0 && c == r && r == o && o == a && a == k)
            return ans;
        
        return -1;
    }
};