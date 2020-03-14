#include "header.hpp"
using namespace std;


bool hasAlternatingBits(int n) {
    int bit = ( n & 1);
    n >>= 1;
    while ( n) {
        if ( bit == ( n & 1)) {
            return false;
        }
        bit = ( n & 1);
        n >>= 1;
    }
    return true;
}


int main() {
    vector<int> nums = { 10, 5, 7, 1};
    for ( auto n : nums) {
        std::cout << "\n " << n << " ::" << ( hasAlternatingBits(n) ? "True" : "False");
    }
    return 0;


}
