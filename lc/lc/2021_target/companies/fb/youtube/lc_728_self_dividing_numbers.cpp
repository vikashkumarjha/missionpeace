/*
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
*/


class Solution {
    bool isSelfDivdingNumber(int num)
    {
        std::string num_str = std::to_string(num);
        for ( auto c : num_str)
        {
                int digit = c - '0';
                if ( digit == 0 || num % digit != 0 )
                        return false;
        }
        return true;
    }
public:
    vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> result;
        for ( int num = left; num <= right; num++)
        {
                if ( isSelfDivdingNumber(num))
                        result.push_back(num);
        }
        return result;
        
    }
};