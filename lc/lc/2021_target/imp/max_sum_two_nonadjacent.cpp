#include<iostream>
#include<string>
#include<vector>


using namespace std;


int findMaxSum(vector<int> &a) 
{

  int n = a.size();
  if ( n == 0) return 0;

  int inclusive = a[0];
  int exclusive = 0;

  for (int i = 1; i < n; i++) {

    int tmp = max(inclusive, exclusive);

    inclusive = exclusive + a[i];
    exlusive = tmp;


  }

}


