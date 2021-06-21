#include <iostream>
using namespace std;


int fab(int n) {
    int a = 1;
    int b = 1;

    
    cout << "\n" << a;
    cout << "\n" << b;


    for ( int i = 2; i < n; i++) {
        int c = a + b;
        cout << "\n" << a + b; 
        b = a;
        a = a + b;

    }


}

int main()
{
    fab(10);

}