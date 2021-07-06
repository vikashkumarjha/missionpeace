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

