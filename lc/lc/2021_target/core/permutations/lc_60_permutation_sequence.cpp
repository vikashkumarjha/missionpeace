/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

*/

#include "../header.hpp"


class Solution {
public:
std::string getNextPermuation(std::string s)
{

    int n = s.length();
    int i;
    
    // find the place where the sequence become decreasing start from end.

    for ( i = n - 1; i > 0 ; i--)
    {
        if ( s[i] >  s[i - 1]){
            break;
        }

    }
    if ( i == 0){
        return "";
    }

    int id1 = i; 
    int id2 = i - 1; 
    
    // find in the right half where it 

    for ( int j = i+1 ; j < n; j++)
    {
        if ( s[j] > s[id2] && s[j] < s[id1] ){
            id1 = j;
        }

    }
    std::swap(s[id1] , s[id2]);
    std::sort(s.begin() + i, s.end());
    return s;

}


string getPermutation(int n, int k) {

    std::string s;
    for ( int i = 1; i <=n; i++){
        s += to_string(i);
    }
    
    while (--k){
        s = getNextPermuation(s);
        
    }
    return s;



}
};