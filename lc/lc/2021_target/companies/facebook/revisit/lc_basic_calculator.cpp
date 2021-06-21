#include <string>
#include <vector>
#include <iostream>


using namespace std;


// how to handle overflow 
/*

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
*/


int parseNum(int &i, string &s) {
    long num = 0;
    while ( i < s.size() && isdigit(s[i])) {
        num = (s[i] - '0') + num * 10;
        i++;
    }
    return num;
}


int parseExpr(int &idx, string &s) {
    vector<long> st;
    char op = '+';
    
    for ( ;idx < s.length() && op != ')'; idx++) {
        if ( isspace(s[idx])) continue;

        long x = (s[idx] == '(') ? parseExpr(++idx, s) : parseNum(idx, s);
        switch(op) {
            case '+':
                st.push_back(x);
                break;
            case '-':
                st.push_back(-x);
                break;
            case '*':
                st.back() = st.back() * x;
                break;
            case '/':
                st.back() = st.back() / x;
                break;
        
        }
        op = s[idx];

    }
    int res = 0;
    for ( int x : st) {
        res += x;
    }

    return res;

}



int calculate(string s) {
    int i = 0;
    return parseExpr(i, s);
}


int main()
{
    string s = "3+2";
    int res = calculate(s);
    cout << "\n " << s << "->" << res;
    return 0;
}




