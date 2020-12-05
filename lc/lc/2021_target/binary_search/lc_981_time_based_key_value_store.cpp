/*
Create a timebased key-value store class TimeMap, that supports two operations.

1. set(string key, string value, int timestamp)

Stores the key and value, along with the given timestamp.
2. get(string key, int timestamp)

Returns a value such that set(key, value, timestamp_prev) was called previously, with timestamp_prev <= timestamp.
If there are multiple such values, it returns the one with the largest timestamp_prev.
If there are no values, it returns the empty string ("").
 

Example 1:

Input: inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
Output: [null,null,"bar","bar",null,"bar2","bar2"]
Explanation:   
TimeMap kv;   
kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1   
kv.get("foo", 1);  // output "bar"   
kv.get("foo", 3); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"   
kv.set("foo", "bar2", 4);   
kv.get("foo", 4); // output "bar2"   
kv.get("foo", 5); //output "bar2"   

Example 2:

Input: inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
Output: [null,null,null,"","high","high","low","low"]

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <sstream>
#include <climits>
#include <cmath>
#include <map>

using namespace std; 
class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<int,std::string>>> _data;
public:
    /** Initialize your data structure here. */
    TimeMap() {
           
    }
    
    void set(string key, string value, int timestamp) {
        _data[key].emplace_back(timestamp,value);
        
    }
    
    string get(string key, int timestamp) {
        std::string result = "";
        if ( _data.count(key) == 0){
            return result;
        }
        std::vector<std::pair<int,std::string>>& resultset = _data[key];
        int low = 0;
        int high = resultset.size() - 1;
        
        while ( low <= high){
            int mid = low + ( high - low) / 2;
            if ( resultset[mid].first  > timestamp){
                high = mid -1;
            }else {
                low = mid + 1;
                result = resultset[mid].second;
            }
        }
        return result;
        
    }
};
