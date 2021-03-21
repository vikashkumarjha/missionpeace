//
//  find_missing_number.cpp
//  finishline
//
//  Created by vikash kumar jha on 12/23/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <stack>
#include <map>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <functional>


using namespace std;



// various find missing number

// find missing number in sorted array

/*
 Find the Missing Number in a sorted array
 Given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list. One of the integers is missing in the list. Write an efficient code to find the missing integer.

 Examples:

 Input : arr[] = [1, 2, 3, 4, 6, 7, 8]
 Output : 5

 Input : arr[] = [1, 2, 3, 4, 5, 6, 8, 9]
 Output : 7
 */
#if 0
int search(int numbers[], int size)
{
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int middle = (right + left) >> 1;
        if (numbers[middle] != middle) {
            if (middle == 0 || numbers[middle - 1] == middle - 1) {
                return middle;
            }
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}
  
int main()
{
    int ar[] = { 1, 2, 3, 4, 5, 6, 7 };
    int size = sizeof(ar) / sizeof(ar[0]);
    cout << "Missing number:" << search(ar, size);
}


// if the array is unsorted..



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
         for ( int i = 0; i < nums.size(); i++)
        {
                //keep swappping till
                while( nums[i] != i  && nums[i] < nums.size())
                {
                        std::swap(nums[i] , nums[nums[i]]);
                }
        }
        int i = 0;
        for ( ; i < nums.size(); i++)
        {
                if ( nums[i] != i) break;

        }
        return i;
        
    }
};
int getMissingNo(int a[], int n)
{
    // For xor of all the elements in array
    int x1 = a[0];
  
    // For xor of all the elements from 1 to n+1
    int x2 = 1;
  
    for (int i = 1; i < n; i++)
        x1 = x1 ^ a[i];
  
    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;
  
    return (x1 ^ x2);
}
  
// Driver Code
int main_missing()
{
    int arr[] = { 1, 2, 4, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = getMissingNo(arr, n);
    cout << miss;
}

#endif
