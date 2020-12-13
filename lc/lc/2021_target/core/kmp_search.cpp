// First we will try to write the basic search

// And what is its complexity and all then we will move to the KMP search


#include "header.hpp"




vector<int> GetMatchingIndex(string p, string s) {

    int pLen = p.size();
    int sLen = s.size();

    vector<int> r;

    for ( int i = 0; i < sLen - pLen + 1; i++ ) {
        int j;
        for ( j = 0; j < pLen; j++) {
            if ( p[j] != s[i+j]) break;
        }
        if ( j == pLen) {
            r.push_back(i);
        }
    }

    return r;
}

// we will do the kmp search

/*How to use lps[] to decide next positions (or to know a number of characters to be skipped)?

We start comparison of pat[j] with j = 0 with characters of current window of text.
We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.
When we see a mismatch
We know that characters pat[0..j-1] match with txt[i-j…i-1] (Note that j starts with 0 and increment it only when there is a match).
We also know (from above definition) that lps[j-1] is count of characters of pat[0…j-1] that are both proper prefix and suffix.
From above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that these characters will anyway match. Let us consider above example to understand this.
txt[] = "AAAAABAAABA" 
pat[] = "AAAA"
lps[] = {0, 1, 2, 3} 

i = 0, j = 0
txt[] = "AAAAABAAABA" 
pat[] = "AAAA"
txt[i] and pat[j] match, do i++, j++

i = 1, j = 1
txt[] = "AAAAABAAABA" 
pat[] = "AAAA"
txt[i] and pat[j] match, do i++, j++

i = 2, j = 2
txt[] = "AAAAABAAABA" 
pat[] = "AAAA"
pat[i] and pat[j] match, do i++, j++

i = 3, j = 3
txt[] = "AAAAABAAABA" 
pat[] = "AAAA"
txt[i] and pat[j] match, do i++, j++

i = 4, j = 4
Since j == M, print pattern found and reset j,
j = lps[j-1] = lps[3] = 3

Here unlike Naive algorithm, we do not match first three 
characters of this window. Value of lps[j-1] (in above 
step) gave us index of next character to match.
i = 4, j = 3
txt[] = "AAAAABAAABA" 
pat[] =  "AAAA"
txt[i] and pat[j] match, do i++, j++

i = 5, j = 4
Since j == M, print pattern found and reset j,
j = lps[j-1] = lps[3] = 3

Again unlike Naive algorithm, we do not match first three 
characters of this window. Value of lps[j-1] (in above 
step) gave us index of next character to match.
i = 5, j = 3
txt[] = "AAAAABAAABA" 
pat[] =   "AAAA"
txt[i] and pat[j] do NOT match and j > 0, change only j
j = lps[j-1] = lps[2] = 2

i = 5, j = 2
txt[] = "AAAAABAAABA" 
pat[] =    "AAAA"
txt[i] and pat[j] do NOT match and j > 0, change only j
j = lps[j-1] = lps[1] = 1 

i = 5, j = 1
txt[] = "AAAAABAAABA" 
pat[] =     "AAAA"
txt[i] and pat[j] do NOT match and j > 0, change only j
j = lps[j-1] = lps[0] = 0

i = 5, j = 0
txt[] = "AAAAABAAABA" 
pat[] =      "AAAA"
txt[i] and pat[j] do NOT match and j is 0, we do i++.

i = 6, j = 0
txt[] = "AAAAABAAABA" 
pat[] =       "AAAA"
txt[i] and pat[j] match, do i++ and j++

i = 7, j = 1
txt[] = "AAAAABAAABA" 
pat[] =       "AAAA"
txt[i] and pat[j] match, do i++ and j++

We continue this way...

*/





 
// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(string pat, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
    int pLen = pat.size();
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < pLen) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 
vector<int> KMPSearch(string pat, string txt) 
{ 
    int pLen = pat.size(); 
    int sLen =  txt.size();
    vector<int> r;
  
    // create lps[] that will hold the longest prefix suffix 
    // values for pattern 
    int lps[pLen]; 
  
    // Preprocess the pattern (calculate lps[] array) 
    computeLPSArray(pat,lps); 
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < sLen) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == pLen) { 
            //printf("Found pattern at index %d ", i - j); 
            r.push_back(i-j);
            j = lps[j - 1]; 
        } 
  
        // mismatch after j matches 
        else if (i < sLen && pat[j] != txt[i]) { 
            // Do not match lps[0..lps[j-1]] characters, 
            // they will match anyway 
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    return r;
} 
 
  



int main()
{
    string pattern = "AABA";
    string txt = "AABAAACAADAABAXYZAABAXXXAABA";

    vector<int> r = GetMatchingIndex(pattern, txt);
    for_each(r.begin(), r.end(), [](int x) {
        cout << x << " ";
    });
    r = KMPSearch(pattern, txt);
    for_each(r.begin(), r.end(), [](int x) {
        cout << x << " ";
    });

    return 0;

}






