#include <iostream>
#include <string>


using namespace std;

/*

Given a string, that contains special character together with alphabets (‘a’ to ‘z’ and ‘A’ to ‘Z’), reverse the string in a way that special characters are not affected.

Examples:

Input:   str = "a,b$c"
Output:  str = "c,b$a"
Note that $ and , are not moved anywhere.  
Only subsequence "abc" is reversed

Input:   str = "Ab,c,de!$"
Output:  str = "ed,c,bA!$"

*/


void reverseSpecial(string &s) {
    int l = 0;
    int r = s.size() - 1;
    while ( l  < r) {
        if ( !isalpha(s[l])) l++;
        else if ( !isalpha(s[r])) r--;
        else {
            swap(s[l++], s[r--]);
        }
    }

}

int main() {
    string s = "a,b$c";
    reverseSpecial(s);
    cout << "\n The value of the string" << s;
    return 0;

}

