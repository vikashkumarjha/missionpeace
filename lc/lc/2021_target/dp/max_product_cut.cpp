//
//  max_product_cut.cpp
//  lc
//
//  Created by vikash kumar jha on 2/23/20.
//  Copyright © 2020 vikash kumar jha. All rights reserved.
//

#if 0

#include "header.hpp"

using namespace std;

int maxProductCut(int n) {
    if ( n == 0 && n == 1) return 1;
    
    int maxVal = 0;
    for (int i = 1; i < n; i++)
        maxVal = max(maxVal, max(i*(n-i), maxProductCut(n-i)*i));
    
      // Return the maximum of all values
      return maxVal;
    
    
}


// A Dynamic Programming solution for Max Product Problem
int maxProd(int n)
{
   int val[n+1];
   val[0] = val[1] = 0;
   
   // Build the table val[] in bottom up manner and return
   // the last entry from the table
   for (int i = 1; i <= n; i++)
   {
      int max_val = 0;
      for (int j = 1; j <= i/2; j++)
         max_val = max(max_val, (i-j)*j, j*val[i-j]);
      val[i] = max_val;
   }
   return val[n];
}



int main() {
    cout << "Maximum Product is " << maxProductCut(10);
   return 0;
}

#endif 
