/*
Given an array of DISTINCT elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f. 
Example:

Input: arr[] = {4, 3, 7, 8, 6, 2, 1} 
Output: arr[] = {3, 7, 4, 8, 2, 6, 1}

Input: arr[] = {1, 4, 3, 2} 
Output: arr[] = {1, 4, 2, 3}

*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


void zigzagCoversion(vector<int> &a) {
    int n = a.size();
    sort(begin(a), end(a));

    for ( int i = 1; i < n; i+= 2) {
        swap(a[i], a[i+1]);
    }

    return;
}
// Program for zig-zag conversion of array  
void zigZag(int arr[], int n)  
{  
    // Flag true indicates relation "<" is expected,  
    // else ">" is expected. The first expected relation  
    // is "<"  
    bool flag = true;  
  
    for (int i=0; i<=n-2; i++)  
    {  
        if (flag) /* "<" relation expected */
        {  
            /* If we have a situation like A > B > C,  
            we get A > B < C by swapping B and C */
            if (arr[i] > arr[i+1])  
                swap(arr[i], arr[i+1]);  
        }  
        else /* ">" relation expected */
        {  
            /* If we have a situation like A < B < C,  
            we get A < C > B by swapping B and C */
            if (arr[i] < arr[i+1])  
                swap(arr[i], arr[i+1]);  
        }  
        flag = !flag; /* flip flag */
    }  
}  


int main()
{
    vector<int> x = {4, 3, 7, 8, 6, 2, 1};
    zigzagCoversion(x);
    for_each(begin(x), end(x), [](int x) {
        cout << x << " ";;
    });
    return 0;
}


