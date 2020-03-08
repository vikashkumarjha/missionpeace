#if 0
#include "header.hpp"

using namespace std;



bool isPowerOfTwo(int num) {
    if ( num > 0 && !(num & num -1)) {
        return true;
    }

    return false;

}


int main() {
    vector<int> nums = { 1, 2, 3, 1024, 123, 64, 99};
    for ( auto n : nums) {
        if ( isPowerOfTwo(n)) {
            std::cout << n << "::" << "Yes\n";
        }else {
            std::cout << n << "::" << "No\n";
        }
    }
}

#endif
