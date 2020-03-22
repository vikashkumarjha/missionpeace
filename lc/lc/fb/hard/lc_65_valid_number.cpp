/*
 * Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

*/


class Solution {
public:
    bool isNumber(string s) {

        int n = s.size(), i = 0, digits = 0, dots = 0;
        //ignore the spaces at the beginning.
        for (; i < n && isspace(s[i]); i++);

        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        //find number of dots and digits
        for (; i < n && (isdigit(s[i]) || s[i] == '.'); i++) {
            isdigit(s[i]) ? digits++ : dots++;
        }
        // validation for dots greater tha1 
        if (!digits || dots > 1) {
            return false;
        }
        if (s[i] == 'e') {
            i++;
            if (s[i] == '+' || s[i] == '-') {
                i++;
            }
            digits = 0;
            for (; i < n && isdigit(s[i]); i++) {
                digits++;
            }
            if (!digits) {
                return false;
            }
        }
        for (; i < n && isspace(s[i]); i++);
        return i == n;

    }
};
