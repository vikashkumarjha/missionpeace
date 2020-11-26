class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if ( cache.count(key)) {
            int res = cache[key].first;
            use(key);
            return res;
            
        }else {
            return -1;
        }
    }
    
    
    void use(int key) {
        auto p = cache[key];
        lru.erase(p.second);
        lru.push_front(key);
        cache[key].second = lru.begin();
        
    }
    
    void put(int key, int value) {
        
        if ( cache.count(key)){
          use(key);
          cache[key] = std::make_pair(value,lru.begin());
          return;
        }
        
        if (cache.size() == cap) {
            int keyToRemove = lru.back(); lru.pop_back();
            cache.erase(keyToRemove);
        }
        lru.push_front(key);
        cache.insert(make_pair(key, make_pair(value,lru.begin())));
        
    }
    
private:
    int cap;
    list<int> lru;
    unordered_map<int, pair<int,list<int>::iterator>> cache;
    
    
};