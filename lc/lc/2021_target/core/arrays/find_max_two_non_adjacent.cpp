#include "../header.hpp"

//Maximum sum such that no two elements are adjacent
int findMaxNonAdjacent(vector<int> &a) {
    int n = a.size();
    if ( n == 0) return 0;
    int exclusive = 0;
    int inclusive = a[0];

    for ( int i = 1; i < n; i++) {
        int tmp = max(inclusive, exclusive);

        inclusive = exclusive + a[i];
        exclusive = tmp;

    }

    return max(inclusive, exclusive);

}

 
int main()
{
    int arr[] = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Maximum sum is " << maxSumSubseq(arr, n);
 
    return 0;
}


int main()
{
    vector<int> a = {5, 5, 10, 100, 10, 5};
    int r = findMaxNonAdjacent(a);

    cout << "\n The value of the result::" << r << "\n";


    return 0;


}




