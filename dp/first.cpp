#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void  f(vector<int> &a, int idx) {
  if ( idx <= 0 ) return a[idx];
  a[idx] = a[idx] + f(a, idx-1);





}


int main()
{
  vector<int> a = { 1, 2, 3, 4, 5};
  int n = a.size();
 f(a, n - 1);
  for_each(begin(a), end(a), [](int x) {
      cout << x << " ";
      });

  return 0;



}
