/*
Given a string num which represents an integer, return true if num is a strobogrammatic number.

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).


*/
class Solution {
public:
    char stroboNumber(const char &num)
    {
        switch(num)
        {
            case '0':
            case '1':
            case '8':
                return num;
            case '6':
                return '9';
            case '9':
                return '6';
            default:
                return NULL;
        }
    }
    bool isStrobogrammatic(string num) {
        int numSize = num.size();
        if(numSize == 0)
            return false;
        
        for(int i = 0, j = numSize-1; i <= j; ++i, --j)
        {             
            if(num[j] != stroboNumber(num[i]))
                return false;
        }
        return true;
    }
};
