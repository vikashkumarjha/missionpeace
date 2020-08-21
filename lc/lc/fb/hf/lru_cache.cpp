class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
            auto item = _cache.find(key);
            if ( item == _cache.end())
            {
                    return -1;
            }
            use(item);
            return item->second.first;
        
    }
    
    void put(int key, int value) {
       //if the item exists just update

       auto item = _cache.find(key);
       if (item != _cache.end()){
           use(item);
           _cache[key] = std::make_pair(value,_lru.begin());
           return;
       } 
       //check capacity...
       if ( _cache.size() == _capacity)
       {
           _cache.erase(_lru.back());
           _lru.pop_back();

       }
       // insert the new key...
       _lru.push_front(key);
       _cache.insert(std::make_pair(key, std::make_pair(value,_lru.begin())));
    }

private:
    int _capacity;
    std::list<int> _lru; //this will have the keys...
    //key , pair of value , iterator to the list...
    std::unordered_map<int,std::pair<int,std::list<int>::iterator> > _cache;
    void use( std::unordered_map<int,std::pair<int,std::list<int>::iterator> >::iterator &it  )
    {
        _lru.erase(it->second.second);
        _lru.push_front(it->first);
        it->second.second = _lru.begin();
    }
    
};