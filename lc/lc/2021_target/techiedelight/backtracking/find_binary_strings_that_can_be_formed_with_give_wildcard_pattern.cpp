/*
 * give a binary pattern with ? as wildcard char , find all possible combinations of binary strings that can be formed by replcing the wildcard character with either 0 or 1 */


#include<iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;


void printAllCombinations(string &pat, int idx)
{
    if ( idx == pat.size())
    {
        cout << "\n" << pat;
        return;
    }

    if ( pat[idx] == '?')
    {
        for ( int k = 0; k < 2; k++)
        {
          pat[idx] = k + '0';
          printAllCombinations(pat, idx+1);
         pat[idx] = '?';
        }
    }
    else {
      printAllCombinations(pat, idx+1);
    }

}



// lests try to the iterative...


void printAllCombinationsIterative(string pat)
{
  stack<string> st;

  st.push(pat);
  size_t idx;

  while ( !st.empty())
  {
    string curr = st.top();
    st.pop();

    if ( (idx = curr.find_first_of('?')) != string::npos)
    {
        for ( int k = 0; k < 2; k++)
        {
          curr[idx] = k + '0';
          st.push(curr);
        }

    }
    else {
      cout << "\n The value of " << curr;
    }
  }


}





int main()
{
  string pattern  = "1?11?";
  //printAllCombinations(pattern, 0);
  printAllCombinationsIterative(pattern);
  return 0;


}


