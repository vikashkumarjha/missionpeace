#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        long mask = 1;
        for ( int i = 0; i < 32; i++) {
            if ( n & mask) {
                ++count;
            }
            mask <<= 1;
        }
        return count;
    }
};

class Solution2 {
public:
	int hammingWeight(uint32_t n) {
		int count= 0;
		while (n != 0) {
			count++;
			n &= (n - 1);
		}
		return count;

	}
};
