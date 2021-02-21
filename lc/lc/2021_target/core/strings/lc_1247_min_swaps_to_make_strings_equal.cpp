/*
You are given two strings s1 and s2 of equal length consisting of letters "x" and "y" only. Your task is to make these two strings equal to each other. You can swap any two characters that belong to different strings, which means: swap s1[i] and s2[j].

Return the minimum number of swaps required to make s1 and s2 equal, or return -1 if it is impossible to do so.

 

Example 1:

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: 
Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
Example 2: 

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: 
Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you can't swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.


*/

/*

conclusion : 
1. two xy or two yx take 1 move to be equal.
2. a single xy and a single yx take 2 move to be equal.

res = xy_cnt/2 + yx_cnt/2
if(xy_cnt%2 + yx_cnt%2 == 1) // can never make a pair
	return -1
else
	return res + xy_cnt%2 + yx_cnt%2;


    1 . find number of xy pairs and yx pairs.
2. if xy pair is odd and yx pair is even, we cant form a solution
3. if yx pair is odd and xy pair is even , we cant form a solution
4. if xy and yx pairs are odd, then there is one pair left from each of the paris. We can swap values with the remaining pairs . So add +2 with the solution
5. if xy and yx pairs are even, just divide the total number of pairs by 2 and return the result.

    */
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for(int i = 0 ; i < s1.length() ; i++){
            if(s1[i] == 'x' && s2[i] == 'y')
                xy++;
            else if(s1[i] == 'y' && s2[i] == 'x')
                yx++;
        }
        int res = 0;
        res = xy/2 + yx/2;
        xy %= 2, yx %= 2;
        if(xy + yx == 1)
            return -1;
        else
            return res+(xy+yx);
    }
};