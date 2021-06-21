Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



class Solution {
private:
    vector<vector<int>> DP;

    bool helper(int i, int j, string s, string p) {
        if (DP[i][j] != -1) return DP[i][j];

        bool result;

        if (j == p.size()) {
            result = (i == s.size());
        } else {
            bool isFirstCMatch = (i < s.size() && (p[j] == s[i] || p[j] == '.'));

            if (j + 1 < p.size() && p[j + 1] == '*')
                result = (helper(i, j + 2, s, p) ||
                        (isFirstCMatch && helper(i + 1, j, s, p)));
            else
                result = isFirstCMatch && helper(i + 1, j + 1, s, p);
        }

        DP[i][j] = result;
        return result;
    }

public:

    // Here * must be followed by Preceding Character
    bool isMatch(string s, string p) {
        int S = s.size();
        int P = p.size();

        DP = vector(S + 1, vector<int>(P + 1, -1));

        helper(0, 0, s, p);

        return DP[S][P] == 1;
    }
};

