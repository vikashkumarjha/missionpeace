class Solution {
public:
    int trailingZeroes(int n) {
   int count = 0;
    long factor = 5;
    int curr = 1;
    while ( curr ) {
        curr = n / factor;
        count += curr;
        factor *= 5;
    }
    return count;
        
}

};