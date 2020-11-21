class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size(), keep = n - k;
        for (char c : num) {
            while (k && res.size() && res.back() > c)              {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        res.resize(keep);
        while (!res.empty() && res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;

    }
};


//Every time scan from the beginning and erase the last digit of the heading non-descending sequence.
class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length();
        int i = 0;
        
        if (k == len)
            return "0";
        
        while (k--)
        {
            i = 0;
            while (i + 1 < len && num[i] <= num[i + 1])
                i++;
            num.erase(num.begin() + i);
        }
        
        i = 0;
        while (i < len && num[i] == '0')
            i++;
        if (i > 0)
            num.erase(num.begin(), num.begin() + i);
        if (num.length() == 0)
            return "0";
            
        return num;
    }
};
