// reveres words in the string



#include <iostream>
#include <string>

using namespace std;



string reverseWords(string s)
{
    reverse(begin(s),end(s));
    int idx = 0;
    for ( int i = 0; i < s.size(); i++)
    {
            if ( s[i] == ' ') {
                reverse(s.begin() + idx, s.begin() + i);
                idx = i+1;
            }
    }
    reverse(s.begin() + idx , s.end());
    return s;
}


int main()
{
    string s = "vikash are you alone";
    string r = reverseWords(s);
    cout << "\n The result:" << r;
    return 0;
}
