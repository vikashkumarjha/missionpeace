class Solution {
public:
    string frequencySort(string s) {
        std::string  result;
        std::unordered_map<char,int> m;
        for ( auto c : s ){
            m[c]++;
        }
        std::vector<std::pair<char,int>>  v;
        for ( auto it = m.begin(); it != m.end(); it++){
            v.push_back(std::make_pair(it->first, it->second));
        }
        std::sort(v.begin(), v.end(), [](auto it1 , auto it2){
                return it1.second > it2.second;
        });

        for ( auto it = v.begin(); it != v.end(); it++){
            int noOfTimes = it->second;
            char currChar = it->first;
            result += std::string(noOfTimes, currChar);
        }
        return result;
    }
};
