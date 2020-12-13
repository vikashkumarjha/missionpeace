// find the nth fab
// f(n) = f(n-1) + f(n-2)
// f(0) = 1, f(1) = 1


#include "../header.hpp"



int fib(int n) {
    if ( n <= 1) return n;
    return fib(n-1) + fib(n-2);
}


int fib2(int n) {
    if ( n <= 1) return n;

    int x = 1;
    int y = 0;
    for (  int i = 0; i < n - 1; i++) {
        int z = x + y;
        y = x;
        x = z;
    }
    return x;

}

int fib3(int n, unordered_map<int,int> &lookup) {
    if ( n <= 1) return n;

    if ( !lookup.count(n) ) {
        lookup[n] = fib3(n-1, lookup) + fib3(n-2, lookup);
    }

    return lookup[n];


}


int main()
{
    cout << "\n The result" << fib(8);
    cout << "\n The result" << fib2(8);
    unordered_map<int,int> m;

    cout << "\n The result" << fib3(8,m);
    return 0;
}