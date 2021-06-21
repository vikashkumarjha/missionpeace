#include <iostream>
#include <vector>

using namespace std;


/*
difference is that due to the existence of duplicates,
 arr[low] == arr[mid] could be possible, 
 the first half could be out of order 
 (i.e. not in the ascending order, e.g. {3, 1, 2, 3, 3, 3, 3}) 
and we have to deal this case separately. 
In that case, it is guaranteed that arr[high] also equal to arr[mid], 
so the condition arr[mid] == arr[low] == arr[high] can be checked
 before the original logic, and if so then move left and right both 
 towards the middle by 1 and repeat.
 */



int search(vector<int> &a, int l, int r, int key)
{
    if ( l > r ) return -1;

    int m = l + ( r - l) / 2;
    if ( a[m] == key) {
        return m;
    }
    
    // The tricky case, just update left and right

    if ( (a[l] == a[m]) && (a[r] == a[m])) {
        l++;
        r--;
        return search(a, l, r, key);
    }

    if ( a[l] <= a[m]) {
        if ( key >= a[l] && key <= a[m]) {
            return search(a, l, m - 1, key);
        }
        return search(a, m+1, r, key);
    }


     if ( key >= a[m] && key <= a[r]) {
            return search(a, m+1, r, key);
        }
      return search(a, l, m-1, key);

}



int main()
{
    vector<int> a = {3, 3, 1, 2, 3, 3 };
    int l = 0;
    int r = a.size() - 1;
    int key = 3;


}