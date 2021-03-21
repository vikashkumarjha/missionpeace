/*


Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

 
Follow up:
Could you solve it using only O(1) extra space?

 

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

*/


#include "../header.hpp"




class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0 ;
        char prev = 0;
        int pos = 0;
        
        for ( auto ch : chars) {
            if ( prev == 0 || prev == ch) {
                count++;
            }else {
                chars[pos++] = prev;
                
                if ( count > 1) {
                    string digits = to_string(count);
                    for ( auto d : digits) {
                        chars[pos++] = d;
                    }
                }
                count = 1;
            }
            prev = ch;
            
        }
        
        chars[pos++] = prev;
        if ( count > 1) {
                string digits = to_string(count);
                for ( auto d : digits) {
                        chars[pos++] = d;
                }
        }
        
        
        return pos;
        
    }
};