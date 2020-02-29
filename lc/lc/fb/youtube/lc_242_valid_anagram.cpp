//
//  lc_242_valid_anagram.cpp
//  lc
//
//  Created by vikash kumar jha on 2/25/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//



#include "header.hpp"

using namespace std;

#if 0



//Given two strings s and t , write a function to determine if t is an anagram of s.



bool isValidAnagram(string s , string t) {
    if ( s.length() != t.length()) return false;
    unordered_map<char,int> m;
    
    for ( auto c : t) {
        m[c]++;
    }
    
    // now go through the source string
    
    for ( auto c : s ) {
        if ( !m.count(c)) return false;
        
        m[c]--;
        if ( m[c] < 0 ) return false;
        
    }
    
    return true;
    
}


int main() {
    
    string s = "anagram";
    string t = "nagaram";
    
    if ( isValidAnagram(s, t)) {
        std::cout << "\n Both anagram";
    }else {
        std::cout << "\n Not anagram.";
    }
    
    return 0;
    
    
    
}

#endif


