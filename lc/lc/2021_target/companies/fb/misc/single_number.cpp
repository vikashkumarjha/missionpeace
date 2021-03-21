//
//  single_number.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/27/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

/*
 Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

 Note:

 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
#if 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0, seenTwice = 0;

    for (int num : nums) {
      // first appearence:
      // add num to seen_once
      // don't add to seen_twice because of presence in seen_once

      // second appearance:
      // remove num from seen_once
      // add num to seen_twice

      // third appearance:
      // don't add to seen_once because of presence in seen_twice
      // remove num from seen_twice
      seenOnce = ~seenTwice & (seenOnce ^ num);
      seenTwice = ~seenOnce & (seenTwice ^ num);
    }

    return seenOnce;
        
    }
};

#endif
