class Solution {
private:
    int parseNum(string & s, int & i, int sign) {
        long long n = 0;
       
        while(i < s.length() && isdigit(s[i])) {
            if (n > INT_MAX/10 || (n == INT_MAX/10 && s[i] - '0' > 7)) {
                return (sign == '+') ? INT_MAX : INT_MIN;
            }
           
            n = s[i++] - '0' + 10 * n;
        }
       
        return n;
    }
   
public:
    int calculate(string s) {
        int i = 0;
        return parseExpr(s, i);
    }
   
    int parseExpr(string & s, int & i) {
        // Here vector is considered as Stack of compuataion.
        //   -- With advantage of iteration allowed in it.
        vector<long long> nums;
        char op = '+';
       
        for (; i < s.length() && op != ')'; i++) {
            if (s[i] == ' ')
                continue;
           
            long long n = (s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i, op));
           
            switch(op) {
                case '+' : nums.push_back(n); break;
                case '-' : nums.push_back(-n); break;
                case '*' : nums.back() = nums.back()*n; break;
                case '/' : nums.back() = nums.back()/n; break;
            }
            op = s[i];
            
        }
       
        int res = 0;
        for (int n : nums)
            res += n;
       
        return res;
    }
       
};
