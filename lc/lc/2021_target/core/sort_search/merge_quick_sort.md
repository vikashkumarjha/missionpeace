This a common question asked in DS interviews that despite of better worst case performance of merge sort, quicksort is considered better than mergesort. There are certain reasons due to which quicksort is better especially in case of arrays:

Auxiliary Space : Mergesort uses extra space, quicksort requires little space and exhibits good cache locality. Quick sort is an in-place sorting algorithm. In-place sorting means no additional storage space is needed to perform sorting. Merge sort requires a temporary array to merge the sorted arrays and hence it is not in-place giving Quick sort the advantage of space.
Worst Cases : The worst case of quicksort O(n2) can be avoided by using randomized quicksort. It can be easily avoided with high probability by choosing the right pivot. Obtaining an average case behavior by choosing right pivot element makes it improvise the performance and becoming as efficient as Merge sort.
Locality of reference : Quicksort in particular exhibits good cache locality and this makes it faster than merge sort in many cases like in virtual memory environment.
Merge sort is better for large data structures: Mergesort is a stable sort, unlike quicksort and heapsort, and can be easily adapted to operate on linked lists and very large lists stored on slow-to-access media such as disk storage or network attached storage. Refer this for details



Quick Sort vs Merge Sort
Partition of elements in the array :
In the merge sort, the array is parted into just 2 halves (i.e. n/2).
whereas
In case of quick sort, the array is parted into any ratio. There is no compulsion of dividing the array of elements into equal parts in quick sort.
Worst case complexity :
The worst case complexity of quick sort is O(n2) as there is need of lot of comparisons in the worst condition.
whereas
In merge sort, worst case and average case has same complexities O(n log n).
Usage with datasets :
Merge sort can work well on any type of data sets irrespective of its size (either large or small).
whereas
The quick sort cannot work well with large datasets.
Additional storage space requirement :
Merge sort is not in place because it requires additional memory space to store the auxiliary arrays.
whereas
The quick sort is in place as it doesn’t require any additional storage.
Efficiency :
Merge sort is more efficient and works faster than quick sort in case of larger array size or datasets.
whereas
Quick sort is more efficient and works faster than merge sort in case of smaller array size or datasets.
Sorting method :
The quick sort is internal sorting method where the data is sorted in main memory.
whereas
The merge sort is external sorting method in which the data that is to be sorted cannot be accommodated in the memory and needed auxiliary memory for sorting.
Stability :
Merge sort is stable as two elements with equal value appear in the same order in sorted output as they were in the input unsorted array.
whereas
Quick sort is unstable in this scenario. But it can be made stable using some changes in code.
Preferred for :
Quick sort is preferred for arrays.
whereas
Merge sort is preferred for linked lists.
Locality of reference :
Quicksort exhibits good cache locality and this makes quicksort faster than merge sort (in many cases like in virtual memory environment).