#include <iostream>
#include <vector>

using namespace std;


// return the index of element  in the sorted array


int helper(vector<int> &a, int l, int r, int val) 
{
    if ( l > r) return -1;

    auto m = l + ( r - l)/2;

    if ( a[m] == val) {
        return m;
    }
    else if ( a[m] > val) {
        return helper(a, l, m -1, val);
    }
    else {
        return helper(a, m+1, r, val);
    }
}

int bs(vector<int> &a, int x) 
{
    int l = 0;
    int r = a.size() - 1;

    int idx = helper(a, l, r, x);
    cout << "\n The value of the idx:" << idx;
    return 0;
}



int bs_iterative(vector<int> &a, int x)
{
  int l = 0;
  int r = a.size() - 1;

  while ( l <= r ) 
  {
    auto m = l + ( r - l) / 2;

    if ( a[m] == x ) return m;
    if ( a[m] > x ) {
      r = m - 1;

    }
    else{
      l = m + 1;
    }
  }

}





int main()
{
    vector<int> a = { 1, 2,3,4, 5, 20, 50, 100};

    int r = bs(a, 20);

    cout << "\n The value of the idx:" << r;

    return 0;



}








