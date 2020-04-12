#include <iostream>
#include <vector>

using namespace std;

/*


Time Complexity: O(n*2)

Auxiliary Space: O(1)

Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order.
 And it takes minimum time (Order of n) when elements are already sorted.

Algorithmic Paradigm: Incremental Approach

Sorting In Place: Yes

Stable: Yes

Online: Yes

Uses: Insertion sort is used when number of elements is small. 
It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
*/


void insertion_sort(vector<int> &v) {
    int n = v.size();

    for ( int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while ( j >= 0 && v[j] >  key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

int main() {
    vector<int> v = { 10, 6, 1, 8, 2};
    insertion_sort(v);
    for ( auto n : v) {
        std ::cout << n << " ";
    }
    return 0;

}
