#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;


class Solution {
  public:
    string longestPalindrome(string s) {
      int n = s.size();
      int idx = 0;
      int maxLength = 0;
      for ( int i = 0; i < n; i++) {
        for ( int j = i; j < n; j++) {
          bool isPalindrom = true;
          for ( int k = 0; k < ( j - i + 1)/2 ; k++) {
            if ( s[i+k] != s[j-k]) {
              isPalindrom = false;
            }
          }
          if ( isPalindrom && ( j - i + 1) > maxLength) {
            idx = i;
            maxLength = ( j - i + 1);
          }
        }
      }
      return s.substr(idx, maxLength);


    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int L = s.size();
        vector<vector<int>> DP(L + 1,vector<int>(L + 1, 0));
       
        int startidx = 0;
        int maxlen   = 0;
               
        int pallinCount = 0;
       
        for (int l = 1; l <= L; l++){
            if (l == 1)
            {
                for (int i = 1; i <= L; i++) {
                    DP[i][i] = 1;
                    startidx = i - 1;
                    maxlen = l;
                }
            }
            else if (l == 2)
            {
                for (int i = 1; i < L; i++) {
                    if (s[i] == s[i - 1]) {
                        DP[i][i + 1] = 1;
                        startidx = i - 1;
                        maxlen = l;
                    }
                }                  
            }
            else
            {
                for(int i = 1; i <= (L - l + 1); i++) {
                    int j = i + l - 1;
               
                    if (DP[i + 1][ j - 1] && s[i - 1] == s[j - 1]){
                        DP[i][j] = 1;
                        startidx = i - 1;
                        maxlen = l;
                    }
                }
            }
        }
       
        cout << "maxlen : " << maxlen << endl;
       
        return s.substr(startidx, maxlen);
       
       
    }
};


int main()
{
  Solution sol;
  string r = sol.longestPalindrome("abbbcd");
  cout << "\n The value of the result: " << r;
  return 0;


}


