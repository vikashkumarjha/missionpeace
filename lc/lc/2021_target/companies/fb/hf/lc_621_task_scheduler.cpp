int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char,int> m;
    for ( auto t : tasks) {
        m[t]++;
    }
    priority_queue<int> maxHeap;
    for ( auto a : m) {
        maxHeap.push(a.second);
    }
    int cycleLength = n + 1;
    int totalInterval = 0;
    while ( !maxHeap.empty()) {
        vector<int> tmp;
        int partialCycle;
        for ( int k = 0; k < cycleLength; k++ ) {
            auto curr = maxHeap.top(); maxHeap.pop();
            tmp.push_back(curr);
            partialCycle++;
        }
        for ( auto a : tmp) {
            if ( --t > 0 ) {
                maxHeap.push(t);
            }
        }

        if ( maxHeap.empty()) {
            totalInterval += partialCycle;
        }else {
            totalinterval += cycleLength;
        }
    }
    return totalinterval;

}
