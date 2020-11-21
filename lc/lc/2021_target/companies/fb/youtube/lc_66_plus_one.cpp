#include "header.hpp"
using namespace std;


vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    int N = digits.size();
    vector<int> result(N, 0);
    for ( int i = N - 1; i >= 0; i++) {
        int val = carry + digits[i];
        carry = val / 10;
        result[i] = val % 10;
    }
    if ( carry) {
        result.insert(result.begin(), carry);
    }

    return result;
}
