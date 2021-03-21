//
//  verifying_alien_dict.cpp
//  finishline
//
//  Created by vikash kumar jha on 2/6/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0


bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char,char> hash;
    int N = order.size();
    
    for ( int i = 0; i < N; i++) {
        hash[order[i]] = 'a' + i;
    }
    
    
    // lets map the
    for ( auto &w : words) {
        for ( auto &c : w) {
            c = hash[c];
        }
        
    }
    
    return is_sorted(words.begin(), words.end());
    
  
       
}


#endif
