class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        int res = -1;
        if ( _cache.count(key)) {
            res = _cache[key].first;
            auto it = _cache[key].second;
            _lru.erase(it);
            _lru.push_front(key);
            _cache[key].second = _lru.begin();
            
        }
        return res;
    }

    void put(int key, int value) {
        // it exists
        if ( _cache.count(key)) {
            auto it = _cache[key].second;
            _lru.erase(it);
            _lru.push_front(key);
            _cache[key].first = value;
            _cache[key].second = _lru.begin();
        }else {
            if ( _lru.size() == _capacity) {

                auto evictKey = _lru.back();
                _lru.pop_back();
                _cache.erase(evictKey);
            }
            _lru.push_front(key);
            _cache[key] = make_pair(value, _lru.begin());

        }
    }
private:
    int _capacity;
    list<int> _lru;
    unordered_map<int,pair<int,list<int>::iterator>> _cache;

};

