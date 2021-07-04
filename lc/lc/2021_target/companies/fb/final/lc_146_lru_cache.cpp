class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;    
    }

    int get(int key) {
        if ( !cache.count(key)) {
            return -1;
        }

        auto e = cache[key];
        lru.erase(e.second);
        lru.push_front(key);
        cache[key].second = lru.begin();
        return e.first;

    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            if ( lru.size() == cap) {
                // remove the oldest record.
                int toRemove = lru.back();
                lru.pop_back();
                cache.erase(toRemove);
            }    
        }

        if (cache.count(key)) {
            auto e = cache[key];
            lru.erase(e.second);
        }

        lru.push_front(key);
        cache[key] = {value, lru.begin()};


    }

private:
    int cap;
    list<int> lru;
    unordered_map<int, pair<int,list<int>::iterator>> cache;

};

