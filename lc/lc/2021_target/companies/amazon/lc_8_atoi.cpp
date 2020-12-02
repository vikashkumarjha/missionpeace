/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered a whitespace character.
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, 231 − 1 or −231 is returned.


Example 1:

Input: str = "42"
Output: 42
Example 2:

Input: str = "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign. Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: str = "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: str = "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical digit or a +/- sign. Therefore no valid conversion could be performed.



*/

class Solution
{
public:
    int myAtoi(string s)
    {

        int i = 0;
        int n = s.length();
        long result = 0;
        int sign = 1;
        for (; i < n;)
        {
            while (std::isspace(s[i]))
                i++;
            if (s[i] == '+' || s[i] == '-')
            {
                sign = (s[i] == '+') ? 1 : -1;
                ++i;
            }

            while (i < n && std::isdigit(s[i]))
            {
                result = result * 10 + (s[i++] - '0');
                if (result * sign >= INT_MAX)
                    return INT_MAX;
                if (result * sign <= INT_MIN)
                    return INT_MIN;
            }

            return (result * sign);
        }
        return result * sign;
    }
};