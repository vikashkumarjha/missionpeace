class Solution {
public:

    struct Record{
    int id;
    std::string status;
    int timestamp;
};
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        std::stack<Record> st;
    std::vector<int> timeSpent(n,0);

    for ( auto log : logs ){
        std::stringstream ss(log);
        Record r;
        std::string token1 , token2, token3;
        std::getline(ss,token1,':');
        std::getline(ss,token2,':');
        std::getline(ss,token3,':');
        r.id = stoi(token1);
        r.status = token2;
        r.timestamp= stoi(token3);
        if ( r.status == "start"){
            st.push(r);
        }
        else {
                // we have encountered an end...
                int timeAdded = r.timestamp - st.top().timestamp + 1;
                timeSpent[r.id] += timeAdded;
                st.pop();

                if ( !st.empty()){
                        timeSpent[st.top().id] -= timeAdded; 
                }
        }
    }
        return timeSpent;
        
    }
};