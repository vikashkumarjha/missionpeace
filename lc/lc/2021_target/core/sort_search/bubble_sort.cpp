#include "header.hpp"


void bubble_sort(vector<int> &a) {
    int n = a.size();
    for ( int i = 0; i < n - 1; i++) {
        // last i elements are already in place
        for ( int j = 0; j < n - 1 -i; j++) {
            if ( a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }

}



int main()
{
    vector<int> a = {10, 5, 6, 8, 20, 2, 3, 1};
    bubble_sort(a);
    for_each(begin(a), end(a), [](int x) {
        cout << x << " ";
    });

    return 0;


}