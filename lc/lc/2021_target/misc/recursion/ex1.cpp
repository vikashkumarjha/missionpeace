#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// write a program to that does the 
// a [ 1 2 3 4] => [ 1 3 6 10]



int f(vector<int> &a, int idx) {
  if ( idx <= 0 ) return a[idx];
  a[idx] = a[idx] + f(a, idx-1);
  return a[idx];
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    int n = a.size();
    f(a, n - 1);
    for_each(begin(a), end(a), [](int x) {
        cout << x << " ";
    });

    return 0;
}
