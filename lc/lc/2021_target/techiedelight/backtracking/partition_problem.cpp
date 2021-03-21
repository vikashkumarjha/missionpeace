/*
 *
 * Give a set of postive numbers find if it can be divided into tow subsets with equal sum or not
 *
 * */


#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;


bool subsetSum(vector<int> &a, int idx, int sum)
{
  if ( sum == 0 )
    return true;

  if ( idx >= a.size() || sum < 0 )
    return false;

  bool exclude = subsetSum(a, idx+1, sum);
  bool include = subsetSum(a, idx+1, sum -a[idx]);

  return include || exclude;

}


bool canPartition(vector<int> &a)
{
  int totalSum = accumulate(begin(a), end(a), 0);
  if (totalSum & 1) {
        return false;

  }

  return subsetSum(a,0, totalSum/2);

}




// Returns true if there exists a subset of `array[0…n)` with the given sum
bool subsetSum(int arr[], int n, int sum)
{
    // `T[i][j]` stores true if subset with sum `j` can be attained
    // using items up to first `i` items
    bool T[n + 1][sum + 1];

    // if 0 items in the list and the sum is non-zero
    for (int j = 1; j <= sum; j++) {
        T[0][j] = false;
    }

    // if the sum is zero
    for (int i = 0; i <= n; i++) {
        T[i][0] = true;
    }

    // do for i'th item
    for (int i = 1; i <= n; i++)
    {
        // consider all sum from 1 to sum
        for (int j = 1; j <= sum; j++)
        {
            // don't include the i'th element if `j-arr[i-1]` is negative
            if (arr[i - 1] > j) {
                T[i][j] = T[i - 1][j];
            }
            else {
                // find the subset with sum `j` by excluding or including the i'th item
                T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
            }
        }
    }

    // return maximum value
    return T[n][sum];
}

// Partition problem – Returns true if given array `arr[0…n-1]` can
// be divided into two subsets with equal sum
bool partition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // return true if the sum is even and the array can be divided into
    // two subsets with equal sum
    return !(sum & 1) && subsetSum(arr, n, sum/2);
}

int main()
{
    // Input: a set of items
    int arr[] = { 7, 3, 1, 5, 4, 8 };

    // total number of items
    int n = sizeof(arr) / sizeof(arr[0]);

    if (partition(arr, n)) {
        cout << "Set can be partitioned";
    }
    else {
        cout << "Set cannot be partitioned";
    }

    return 0;
}

int main()
{
  vector<int> a =  { 7, 3,1,4,4,8};
  if ( canPartition(a)) {
    cout << "\n It can be partitioned into two subsets equally.";

  }else {
    cout << "\n It can not  be partitioned into two subsets equally.";
  }

}
