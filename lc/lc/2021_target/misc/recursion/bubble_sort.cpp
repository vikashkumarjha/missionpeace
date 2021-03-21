#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void bubble_sort(vector<int> &a) {
    int n = a.size();

    for ( int i = 0; i < n; i++) {
        for ( int j = i + 1; j < n; j++) {
            if ( a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}


void bubble_sort_rec(vector<int> &a, int idx) {
    if ( idx < 0) return;
     for ( int i = 0; i < idx; i++) {
        for ( int j = i + 1; j < idx; j++) {
            if ( a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }

    bubble_sort_rec(a, idx - 1);

}





int main()
{
    vector<int> a = { 11, 10, 1, 20, 100, 5};
    bubble_sort_rec(a, a.size());
    for_each(begin(a), end(a), [](int x){
        cout << x << " ";
    });

    return 0;
}


