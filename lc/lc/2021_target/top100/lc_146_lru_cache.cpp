#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class LRUCache
{
private:
    int _capacity;
    list<int> _lru; //keys
    unordered_map<int, pair<int, list<int>::iterator>> _cache;
    void use(unordered_map<int, pair<int, list<int>::iterator>>::iterator &it)
    {
        _lru.erase(it->second.second);
        _lru.push_front(it->first);
        it->second.second = _lru.begin();
    }

public:
    LRUCache(int capacity)
    {
        _capacity = capacity;
    }

    int get(int key)
    {
        if (_cache.count(key))
        {
            auto t = _cache.find(key);
            use(t);
            return t->second.first;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto item = _cache.find(key);
        if (item != _cache.end())
        {
            // we have found in cache.
            use(item);
            _cache[key] = make_pair(value, _lru.begin());
            return;
        }
        //cleanup the oldest element.
        if (_cache.size() == _capacity)
        {
            _cache.erase(_lru.back());
            _lru.pop_back();
        }
        _lru.push_front(key);
        _cache.insert(make_pair(key, make_pair(value, _lru.begin())));
    }
};
int main()
{
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1); // returns 1
    cache.put(3, 3);      // evicts key 2
    cout << cache.get(2); // returns -1 (not found)
    cache.put(4, 4);      // evicts key 1
    cout << cache.get(1); // returns -1 (not found)
    cout << cache.get(3); // returns 3
    cout << cache.get(4); // returns 4
}