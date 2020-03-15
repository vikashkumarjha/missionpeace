//Use the first string in strs as the baseline and add one letter to the lcp at
//at time if all strings have that letter in the correct position.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp;
        if (strs.empty()) {
            return lcp;
        }
        int m = strs.size(), n = strs[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (strs[j].size() == i || strs[j][i] != strs[0][i]) {
                    return lcp;
                }
            }
            lcp += strs[0][i];
        }
        return lcp;
    }


};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }
        string prefix = commonPrefix(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); ++i)
        {
            prefix = commonPrefix(prefix, strs[i]);
        }
        return prefix;
    }

    string commonPrefix(const string& s1, const string& s2)
    {
        string prefix = "";
        for (int i = 0; i < s1.size() && s2.size(); ++i)
        {
            if (s1[i] == s2[i])
            {
                prefix += s1[i];
            }
            else
            {
                return prefix;
            }
        }
        return prefix;
    }
};
