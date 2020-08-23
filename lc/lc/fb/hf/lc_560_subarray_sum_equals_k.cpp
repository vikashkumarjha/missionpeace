int subarraySum(vector<int>& nums, int k) {
    if ( nums.empty()) return 0;
    int N = nums.size();
    int count = 0;
    for ( int s = 0; s < N; s++) {
        int sum = 0;
        for ( int e = s; e < N; e++) {
            sum += nums[e];
            if ( sum == k) {
                ++count;
            }
        }
    }
    return count;
}


int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> m;
    m[0] = 1;
    int count = 0;
    int sum = 0;
    for ( auto n : nums) {
        sum += n;
        if ( m.count(sum - k)) {
            count += m[sum -k ];
        }
        m[sum]++;

    }
    return count;
}



