// count the number of bits 

#include<iostream>
#include<vector>
using namespace std;


int count_bits(unsigned int n) {
    int count = 0;
    while ( n ) {
        count += ( n & 1);
        n >>= 1;
    }
    return count;
}

int count_bits_2(unsigned int n) {
    int count = 0;
    while ( n) {
        count++;
        n &= ( n - 1);
    }
    return count;
}


int BitsSetTable256[256]; 

void initialize()
{
    // To initially generate the
    // table algorithmically
    BitsSetTable256[0] = 0;
    for (int i = 0; i < 256; i++)
    {
        BitsSetTable256[i] = (i & 1) +
        BitsSetTable256[i / 2];
    }
}

// Function to return the count
// of set bits in n
int countSetBits(int n)
{
    return (BitsSetTable256[n & 0xff] +
            BitsSetTable256[(n >> 8) & 0xff] +
            BitsSetTable256[(n >> 16) & 0xff] +
            BitsSetTable256[n >> 24]);
}

int main() {
    vector<int> input = { 1, 2, 3, 4 ,5 , 7, 10};
    initialize();

    for ( auto n : input) {
        std::cout << "\n";
        std::cout << n << "::" << count_bits(n) << " bits\n";
        std::cout << n << "::" << count_bits_2(n) << " bits\n";
        std::cout << n << "::" << countSetBits(n) << " bits\n";
    }
    return 0;

}

