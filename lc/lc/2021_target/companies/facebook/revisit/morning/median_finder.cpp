class MedianFinder {
public:
    /** initialize your data structure here. */
    int n = 0;
    multiset<int> ms;
    multiset<int> :: iterator iter;

    void addNum(int num) {
        if(n == 0) {
            ms.insert(num);
            iter = ms.begin();
            n++;
            return;
        } 
        n++;
        ms.insert(num);
        if(n % 2 == 0) {
            if(num < *iter) {
                iter = prev(iter);
            }
        } else {
            if(num >= *iter) {
                iter = next(iter);
            }
        }
        
    }
    
    double findMedian() {
        if(n % 2 == 1) {
            return *iter;
        } else {
            return (double)(*iter+*next(iter)) / 2.0;
        }
    }
};


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
