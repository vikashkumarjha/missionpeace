//
//  LRU.cpp
//  finishline
//
//  Created by vikash kumar jha on 11/3/19.
//  Copyright © 2019 vikash kumar jha. All rights reserved.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRU {
public:
    LRU(int capacity) : _capacity(capacity) {}
    void put(int key, int value);
    int get(int key);
private:
    size_t _capacity;
    std::list<int> _lru;
    std::unordered_map<int,pair<int,std::list<int>::iterator>> _cache;
    void use(std::list<int>::iterator&);
};

void LRU::use(std::list<int>::iterator &it) {
        int k = *it;
        int v = _cache[k].first;
        _lru.erase(it);
        _lru.insert(_lru.begin(), v);
        _cache[k].second = _lru.begin();
}


int LRU::get(int key) {
    if ( _cache.count(key) == 0 ){
        throw std::logic_error("key not found");
    }
    use(_cache[key].second);
    return _cache[key].first;
}

void LRU::put(int key, int value){
    // have take care of the size
    if ( _cache.size() == _capacity ){
        int valueToErase = _lru.back();
        _cache.erase(valueToErase);
        _lru.pop_back();
    }

    if ( _cache.count(key) == 0 ){
        _lru.insert(_lru.begin(), key);
        _cache.insert(make_pair(key, make_pair(value,_lru.begin() )));
    }else {
        use(_cache[key].second);
    }

}

int main_lru()
{
    LRU lru(3);
    lru.put(1,2);
    lru.put(2,4);
    lru.put(3,8);
    lru.put(4,9);

    std::cout << "the value of the lru" << lru.get(2);
    std::cout << "the value of the lru" << lru.get(1);
    return -1;

}
