#include <iostream>
#include <vector>

using namespace std;


/*
Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.

Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

Auxiliary Space: O(1)

Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

Sorting In Place: Yes

Stable: Yes

*/

void bubble_sort(vector<int> &nums) {
    int n = nums.size();

    for ( int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for ( int j = 0; j < n - i - 1; j++) {
            if ( nums[j] > nums[j+1]) {
                swapped = true;
                swap(nums[j], nums[j+1]);
            }
        }
        if ( !swapped) {
            break;
        }
    }
}

int main() {
    vector<int> nums = { 1, 99, 10, 100, 5};
    bubble_sort(nums);
    for ( auto n : nums ) {
        cout << n << " ";
    }
    return 0;
}
