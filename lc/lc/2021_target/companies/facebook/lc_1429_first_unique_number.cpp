/*
You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
 

Example 1:

Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output: 
[null,2,null,2,null,3,null,-1]
Explanation: 
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1
*/


class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (auto num : nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        if (!_data.empty())
            return _data.front();
        return -1;
    }
    
  
    
    void add(int value) {
        if (_cache.count(value)) {
           auto it = _cache[value];
           if ( it != _data.end()){
               _data.erase(it);
               
           }
           _cache[value] = _data.end();
          
            
        }else {
            _data.push_back(value);
            _cache[value] = std::prev(_data.end());
            
        }
        
        
    }
private:
    list<int> _data;
    unordered_map<int, list<int>::iterator> _cache;
};