class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set.
     * Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if ( m.find(val) != m.end())
            return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }

    /** Removes a value from the set.
     * Returns true if the set contained the specified element. */
    bool remove(int val) {
        if ( m.find(val) == m.end())
            return false;

        // it means it exist...
        auto lastElement = nums.back();
        m[lastElement] = m[val];
        nums[m[lastElement]] = lastElement;
        nums.pop_back();
        m.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int,int> m;
};
