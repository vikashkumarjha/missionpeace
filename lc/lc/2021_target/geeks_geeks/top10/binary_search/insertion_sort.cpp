#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


void insertion_sort(vector<int> &a)
{
    for (int i = 1; i < a.size(); i++)
    {
        int key = a[i];
        int j = i - 1;
        while ( j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main()
{
    vector<int> a = { 10, 1, 12, 16, 5, 20};
    insertion_sort(a);
    for_each(begin(a), end(a), [](int x){
        cout << x << " ";
    });

    return 0;
}