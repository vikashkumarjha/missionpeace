#include "../header.hpp"
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
     int carry = 1;// as we  need to add 1 so thats why 
     int n = digits.size();
     int j = n - 1;
     std::vector<int> result(n);
     for ( ; j >=0 ; --j)
     {
          int val  = carry + digits[j];
          carry = val / 10;
          result[j] = val % 10;

     }
     if ( carry)
        result.insert(result.begin(),carry);
    return result;
        
    }
};