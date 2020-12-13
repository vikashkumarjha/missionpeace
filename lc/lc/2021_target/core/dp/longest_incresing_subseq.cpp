// Longest increeasing subs

/*

The longest increasing subsequence problem is to find a subsequence of a given sequence in 
which the subsequence elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.</p>
<p>For example, longest increasing subsequence of 
[0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
 is [0, 2, 6, 9, 11, 15]
This subsequence has length 6; the input sequence has no 7-member increasing subsequences. The longest increasing subsequence in this example is not unique.</p>
or instance, <code>[0, 4, 6, 9, 11, 15]</code> or <code>[0, 4, 6, 9, 13, 15]</code> are other increasing subsequences of equal length in the same input sequence.<br />
&nbsp;</p>
<p>&nbsp;<br />
The idea is to use recursion to solve this problem. For each item, there are two possibilities &#8211;</p>
<ol>
<li>We include current item in LIS if it is greater than the previous element in LIS and recur for remaining items.<br />
&nbsp;</li>
<li>We exclude current item from LIS and recur for remaining items.</li>
</ol>
<p>Finally, we return maximum value we get by including or excluding current item. The base case of the recursion would be when no items are left.</p>

*/

#include "../header.hpp"


int LIS(vector<int> &a, int idx, int prev) {

    if ( idx == a.size()) return 0;

    //exclusion case
    int x = LIS(a, idx+1, prev);

    int y = 0;
    if ( a[idx] > prev) {
        y = 1 + LIS(a, idx+1, a[idx]);
    }

    return max(x, y);

}



int LIS_DP(vector<int> &a) {
    int n = a.size();
    vector<int> dp(n,0); 
    // longest increasing subsequence ending with a[0] has length 1
    dp[0] = 1;

    for ( int i = 1; i < n; i++) {
        for ( int j = 0; j < i; j++) {
            if ( a[i] > a[j] ) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());


}


int main()
{
    vector<int> a = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    
    int res = LIS(a, 0, INT_MIN);
    cout << "\n THe value of the result:" << res;

    res = LIS_DP(a);
    cout << "\n THe value of the result:" << res;
}



#include <iostream>
#include <vector>
using namespace std;
 
// Iterative function to find longest increasing subsequence
// of given array
void findLIS(int arr[], int n)
{
    // LIS[i] stores the longest increasing subsequence of subarray
    // arr[0..i] that ends with arr[i]
    vector<int> LIS[n];
 
    // LIS[0] denotes longest increasing subsequence ending with arr[0]
    LIS[0].push_back(arr[0]);
 
    // start from second element in the array
    for (int i = 1; i < n; i++)
    {
        // do for each element in subarray arr[0..i-1]
        for (int j = 0; j < i; j++)
        {
            // find longest increasing subsequence that ends with arr[j]
            // where arr[j] is less than the current element arr[i]
 
            if (arr[j] < arr[i] && LIS[j].size() > LIS[i].size())
                LIS[i] = LIS[j];
        }
 
        // include arr[i] in LIS[i]
        LIS[i].push_back(arr[i]);
    }
 
    // uncomment below lines to print contents of vector LIS
    /* for (int i = 0; i < n; i++)
    {
        cout << "LIS[" << i << "] - ";
        for (int j : LIS[i])
            cout << j << " ";
        cout << endl;
    } */
 
    // j will contain index of LIS
    int j;
    for (int i = 0; i < n; i++)
        if (LIS[j].size() < LIS[i].size())
            j = i;
 
    // print LIS
    for (int i : LIS[j])
        cout << i << " ";
}
 
int main()
{
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(arr)/sizeof(arr[0]);
 
    findLIS(arr, n);
 
    return 0;
}








