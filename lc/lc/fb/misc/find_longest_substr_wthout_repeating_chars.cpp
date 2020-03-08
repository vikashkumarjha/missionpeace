//
//  find_longest_substr_wthout_repeating_chars.cpp
//  finishline
//
//  Created by vikash kumar jha on 10/24/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include<string>
#include <unordered_map>

using namespace std;


int maxSubstrWithoutRepeatingChars(string &s){
    int left = 0;
    int right = 0;
    int maxLength = 0;
    unordered_map<char,int> m;
    
    for ( ; right < s.length(); right++){
        if ( m.count(m[right])){
            left = std::max(left, m[s[right]]);
        }
        maxLength = max(maxLength, right - left + 1);
        m[s[right]] = right + 1;
            
        
    }
    return maxLength;
}

int main_2()
{
    string s1 = "abcabcbb";
    std::cout << "Max substring without repeating chars:" << maxSubstrWithoutRepeatingChars(s1);
    
    return 0;
}
