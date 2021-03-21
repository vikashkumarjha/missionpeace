/*
 message containing letters from A-Z is being encoded to numbers using the following mapping way:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.

Given the encoded message containing digits and the character '*', return the total number of ways to decode it.

Also, since the answer may be very large, you should return the output mod 109 + 7.

Example 1:
Input: "*"
Output: 9
Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".

*/

const int MOD = 1e9 + 7;

int cnt_substs(char c1, char c2) {
    if (c1 == '*' && c2 == '*') {
        return 15; // can't substitute * with 0.
    } else if (c1 == '*') {
        if (c2 <= '6') {
            return 2;
        } else {
            return 1;
        }
    } else if (c2 == '*') {
        if (c1 == '1') {
            return 9;
        } else if (c1 == '2') {
            return 6;
        } else {
            return 0;
        }
    } else {
        if (c1 > '2' || c1 == '0') {
            return 0;
        } else if (c1 == '2') {
            return c2 <= '6';
        } else {
            return 1;
        }
    }
}

class Solution {
public:
    int numDecodings(string s) {
        vector<int> f(s.length() + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= s.length(); ++i) {
            if (s[i - 1] == '*') {
                f[i] = (f[i - 1] * 1ll * 9) % MOD;
            } else if (s[i - 1] != '0') {
                f[i] = f[i - 1];
            }
            
            if (i - 2 >= 0) {
                f[i] = (f[i] + f[i - 2] * 1ll * cnt_substs(s[i - 2], s[i - 1])) % MOD;
            }
        }
        return f[s.length()];
    }
};