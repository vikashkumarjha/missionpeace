/*
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * Note:
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 *
 * */

#include "header.hpp"
using namespace std;



string minWindow(string s, string t) {
    int N1 = s.length();
    int N2 = t.length();


    if ( N2 > N1) return "";
    int hash_pat[256] = {0};
    int hash_src[256] = {0};
    int minWindowSize = INT_MAX;

    // first fill the target patterns
    for ( auto c : t) {
        hash_pat[c]++;
    }
    // do the window mechanism
    int l = 0;

    int index = -1;
    int count = 0;

    for ( int r = 0; r < N1; r++) {
        hash_src[s[r]]++;
        if ( hash_pat[s[r]] != 0 && hash_src[s[r]] <= hash_pat[s[r]]) {
            count++;
        }

        if ( count == N2) {
            // we got the window
            while ( hash_pat[s[l]] == 0 || hash_pat[s[l]] < hash_src[s[l]]) {
                if ( hash_pat[s[l]] < hash_src[s[l]]) {
                    hash_src[s[l]]--;
                }
                l++;
            }

            int winLen = r - l + 1;
            if ( winLen < minWindowSize ) {
                index = l;
                minWindowSize = winLen;
            }

        }

    }

    return ( index == -1) ? "" : s.substr(index, minWindowSize);
}


int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";


    string result = minWindow(s, t);
    std::cout << "\n Minimum window" << result;

}
