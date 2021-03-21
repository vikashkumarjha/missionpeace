
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int power(int x, int n) {
    if ( n == 0) {
        return 1;
    }
    if ( n == 1) {
        return x;
    }

    return x * power(x, n -1);

}
int power2(int x, int n) {
    if ( n == 0) {
        return 1;
    }
    if ( n == 1) {
        return x;
    }

    if ( n & 1) {
        return x * power2(x, n -1);
    }else {
        return power2(x*x, n/2);
    }

}




int main()
{
    int res = power2(2, 5);
    cout << "\n The result:" << res;


}