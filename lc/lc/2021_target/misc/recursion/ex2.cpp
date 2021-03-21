// compute the sum of numbers 1 to n using recursion

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int f(vector<int> &a, int idx) {
    if ( idx == 0) {
        return 0;
    }
    if ( idx == 1) {
        return a[idx-1];
    }

    return a[idx-1] + f(a, idx-1);

}



int main()
{
    vector<int> a = { 1, 2, 3, 4};

    int res = f(a, a.size());
    cout << "\n The value of the result:" << res;
    return 0;


}
