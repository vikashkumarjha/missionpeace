vector<int> mp(26,0);

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        for(int i=0; i<order.size(); i++)
            mp[order[i] - 'a'] = i;

        vector<string> temp = words;
        sort(words.begin(), words.end(), comp);

        return (temp == words);
    }

    static bool comp(string a, string b)
    {
        int m = min(a.length(), b.length());

        for(int i=0; i<m; i++)
            if(a[i] != b[i]) return (mp[a[i] - 'a'] < mp[b[i] - 'a']);

        return a.length() < b.length();
    }
};
