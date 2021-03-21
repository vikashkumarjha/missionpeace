#include<iostream>
#include<string>


using namespace std;




void findMin(string s, int n, int k, string &res)
{
  if ( res.compare(s) > 0 ) 
  {
      res = s;
  }
  if ( k < 1)
    return;


  for ( int i = 0; i < n; i++)
  {
    for ( int j = i + 1; j < n; j++)
    {
      if ( s[i] > s[j])
      {
        swap(s[i], s[j]);
        findMin(s, n, k -1, res);
        swap(s[i], s[j]);
      }

    }

  }


}



int main()
{
  string s = "934561";
  int k = 1;

  string res = s;

  findMin(s, s.size(), k, res);

  cout << "\n The value of the result: " << res;

  return 0;




}



