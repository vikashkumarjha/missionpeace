//
//  add_strings_easy.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/13/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;



string add_strings(string s1, string s2) {
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    std::string result;
    // lets start summing from the
    int N = static_cast<int> (s1.length());
    int M = static_cast<int>(s2.length());
    int carry = 0;
    for (int i = 0; i < N || i < M; i++){
        int x = (i < N) ?  (s1[i] - '0') : 0;
        int y  = (i < M) ? (s2[i] - '0') : 0;
        int sum = x + y + carry;
        result += to_string( sum % 10);
        carry = sum / 10;
        
    }
    if ( carry ){
        result += "1";
    }
    
    std::reverse(result.begin(), result.end());
    return result;
    
}


int main_add_strs() {
    auto s1 = "123";
    auto s2 = "956";
    
    std::cout << "The result" << add_strings(s1,s2);
    return 0;
}



