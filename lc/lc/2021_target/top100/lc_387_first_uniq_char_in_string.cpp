#include "../header.hpp"

class Solution
{
public:
    int firstUniqChar(string s)
    {
        int ans = -1;
        if (s.empty())
            return ans;
        std::unordered_map<char, int> m;

        for (int i = 0; i < s.length(); ++i)
        {
            m[s[i]]++;
        }

        for (int i = 0; i < s.length(); ++i)
        {
            if (m[s[i]] == 1)
                return i;
        }
        return ans;
    }
};