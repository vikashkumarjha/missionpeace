/*
You are given a string containing only 4 kinds of characters 'Q', 'W', 'E' and 'R'.

A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make the original string s balanced.

Return 0 if the string is already balanced.

 

Example 1:

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.
Example 2:

Input: s = "QQWE"
Output: 1
Explanation: We need to replace a 'Q' to 'R', so that "RQWE" (or "QRWE") is balanced.


One pass the all frequency of "QWER".
Then slide the windon in the string s.

Imagine that we erase all character inside the window,
as we can modyfy it whatever we want,
and it will always increase the count outside the window.

So we can make the whole string balanced,
as long as max(count[Q],count[W],count[E],count[R]) <= n / 4.

*/

class Solution {
public:
    int balancedString(string s) {
        unordered_map<int, int> count;
        int n = s.length(), res = n, l = 0, k = n / 4;
        for (int j = 0; j < n; ++j) {
            count[s[j]]++;
        }
        for (int r = 0; r < n; ++r) {
            count[s[r]]--;
            while (l < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
                res = min(res, r - l + 1);
                count[s[l]] += 1;
                l++;
            }
        }
        return res;
        
    }
};