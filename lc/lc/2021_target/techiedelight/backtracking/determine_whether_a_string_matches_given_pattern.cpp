/*
 *Given a string and pattern , determine whether a string matches with given patten.
 eg. string : codesleepcode
     pattern : xyx

output:
  x = code
  y = sleep

 *
 *
*/






#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;



bool isMatch(string s, int sIdx, string pat, int pIdx, unordered_map<char,string> &ha)
{

  int n = s.size();
  int m = pat.size();

  if ( sIdx == n && pIdx == m)
  {
    return true;
  }

  if ( sIdx == n || pIdx == m)
    return false;


  char curr = pat[pIdx];

  if ( ha.count(curr)) {

    string s1 = ha[curr];
    int k = s1.size();

    if ( s.substr(sIdx,k).compare(s1)) {
      return false;
    }

    return isMatch(s, sIdx + k, pat, pIdx+1, ha);

  }

  // process all remaining characters

  for ( int k = 1; k <= n - sIdx; k++)
  {

    ha[curr] = s.substr(sIdx, k);
    if ( isMatch(s, sIdx + k, pat, pIdx+1,ha)) {
      return true;
    }

    ha.erase(curr);
  }
  return false;



}





int main()
{

  string s = "codesleepcode";
  string pat = "xyx";


  unordered_map<char,string> m;

  if (isMatch(s, 0, pat, 0, m))
  {
    for ( auto x : m)
    {
        cout << "\n " << x.first << "::" << x.second;
    }

  }
  else {
    cout << "\n pattern does not match";

  }




}




