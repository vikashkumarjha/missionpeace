/*
 * Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

*/
#include "header.hpp"
using namespace std;


string reverseString(string s) {

    int l = 0;
    int r = s.length() - 1;
    while ( l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
    }
    return s;
}
