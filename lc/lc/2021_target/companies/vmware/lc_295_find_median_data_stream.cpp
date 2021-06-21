/*
If current size is even, we try to add the new element to the min heap
If the new number to be added is greater than the root in min heap. 
OK, we push the number into min heap.
However, if the new number to be added is smaller than the largest number 
in the other heap (root node in max heap), 
this number should be in the max heap but not the min heap we intend to add to. 
So we add the new number to max heap instead of min heap. 
But, we still want to keep both heaps balanced in size. 
So we pop the top number in max heap (which we added the new element into), and push it into the min heap (which we intended to add one into in this round).



If current size is odd, we try to add the new element to the max heap
If the new number to be added is smaller than the root in max heap. OK, we push the number into max heap.
Similarly, if the new number to be added is greater than the smallest number in the other heap. We stil have to the same procedure according to the above case.

*/

#include <queue>
#include <multiset>
using namespace std;


class MedianFinder {
public:
    // Constructor
    MedianFinder(){
        count = 0;
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        if (count % 2 == 0){
            if (minHeap.empty()){
                 minHeap.push(num);
            }else{
                if (num <= maxHeap.top()){
                    maxHeap.push(num);
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                }else {
                    minHeap.push(num);
                }
            }
        }else{
            if (num >= minHeap.top()){
                minHeap.push(num);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }else{
                maxHeap.push(num);
            }
        }
        
        count ++;
        
        
        
        // cout << "count = " << count<< endl;
        // cout << "maxHeap: ";
        // print_queue(maxHeap);
        // cout << endl << "minHeap: ";
        // print_queue(minHeap);
        // cout << endl;
    }

    // Returns the median of current data stream
    double findMedian() {
        return count % 2 == 0 ? double(minHeap.top() + maxHeap.top()) / 2 : minHeap.top();
    }
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, std::greater<int> >  minHeap;
    int count;
};


class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;

public:
    MedianFinder()
        : lo_median(data.end())
        , hi_median(data.end())
    {
    }

    void addNum(int num)
    {
        const size_t n = data.size();   // store previous size

        data.insert(num);               // insert into multiset

        if (!n) {
            // no elements before, one element now
            lo_median = hi_median = data.begin();
        }
        else if (n & 1) {
            // odd size before (i.e. lo == hi), even size now (i.e. hi = lo + 1)

            if (num < *lo_median)       // num < lo
                lo_median--;
            else                        // num >= hi
                hi_median++;            // insertion at end of equal range
        }
        else {
            // even size before (i.e. hi = lo + 1), odd size now (i.e. lo == hi)

            if (num > *lo_median && num < *hi_median) {
                lo_median++;                    // num in between lo and hi
                hi_median--;
            }
            else if (num >= *hi_median)         // num inserted after hi
                lo_median++;
            else                                // num <= lo < hi
                lo_median = --hi_median;        // insertion at end of equal range spoils lo
        }
    }

    double findMedian()
    {
        return (*lo_median + *hi_median) * 0.5;
    }
};
