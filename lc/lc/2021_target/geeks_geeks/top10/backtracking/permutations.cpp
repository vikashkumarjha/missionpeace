#include <iostream>
#include <string>
#include <vector>

using namespace std;



void helper(string s, int idx, vector<string> &r)
{
    if ( idx == s.size() - 1) {
        r.push_back(s);
        return;
    }
    for ( int k = idx; k < s.size(); k++) {
        swap(s[k], s[idx]);
        helper(s, idx+1, r);
        swap(s[k], s[idx]);
    }

}



void getAllPermutations(string s, vector<string> &res)
{
    helper(s, 0, res);
}
int main()
{

    string s = "abc";
    vector<string> res;

    getAllPermutations(s, res);

    for ( auto p : res) {
        cout << "\n " << p;
        
    }

    return 0;


}

