/*
Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 



For example, 12321 is a palindrome.

*/

// trick is to generate the next palindrome
// say for example for numer 10
// s = 10 , t = 01
// now pop form s, and append t
// s + t

#include "header.hpp"

class Solution {
public:
    int primePalindrome(int N) {
        if(N <= 2) return 2;
        if(N>7 && N<=11) return 11;
        for(int i = 1; i < 999999; i++){
            auto palin = palinize(i);
            if(palin >= N && isPrime(palin)) return palin;
        }
        return -1;
    }
    
    int palinize(int x){
        auto s = to_string(x), t = s;
        reverse(t.begin(), t.end());
        s.pop_back();
        return stoi(s+t);
    }
    
    bool isPrime(int x){
        if(x%2==0) return false;
        int sq = int(sqrt(x)) + 1;
        for(int i = 3; i<=sq; i+= 2)
            if(x % i == 0) return false;
        return true;
    }
};


