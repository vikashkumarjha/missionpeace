/*
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.



*/

class Solution {

    private:
    int romanValue(char ch){
    int value = -1;
    switch ( ch ){
    case 'I':
            value = 1;
            break;

    case 'V':
            value = 5;
            break;

    case 'X':
            value = 10;
            break;

    case 'L':
            value = 50;
            break;

    case 'C':
            value = 100;
            break;

    case 'D':
            value = 500;
            break;

    case 'M':
            value = 1000;
            break;
    default :
        break;
    }
    return value;
}

public:

int romanToInt(string s) {
    int result = 0;
    for ( int i = 0; i < s.length(); i++)
    {
        int s1 = romanValue(s[i]);
        if ( i + 1 < s.length()){
            int s2 = romanValue(s[i+1]);
            if ( s1 >= s2){
                result += s1;
            }else {
                result += (s2 - s1);
                i++;
            }
        }else {
            result += s1;
        }
    }
    return result;
}

};
