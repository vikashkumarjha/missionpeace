/*
Find the length of the longest substring T of a given string (consists of lowercase letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.



In the first pass I record counts of every character in a hashmap
in the second pass I locate the first character that appear less than k times in the string. this character is definitely not included in the result, and that separates the string into two parts.
keep doing this recursively and the maximum of the left/right part is the answer.x	

*/


class Solution {
public:
    int longestSubstring(const string &s, int k) {
        return helper(s, 0, s.size(), k);
    }
    int helper(const string &s, int beg, int end, int k){
        if(end - beg < k) return 0;
        int cnt[26]{};
        for(int i = beg; i < end; ++i) 
            ++cnt[s[i]-'a'];
        for(int i = beg; i < end; ++i)
        if (cnt[s[i] - 'a'] < k)
            return max(helper(s, beg, i, k), 
                       helper(s, i + 1, end, k));
        return end - beg;
    }
};