struct T {
    int id;
    string status;
    int ts;
    
};

class Solution {
public:
    
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        vector<int> timespent(n,0);
        stack<T> st;
        for ( auto l: logs) {
            stringstream ss(l);
            string id,status,ts;
            getline(ss,id,':');
            getline(ss, status, ':');
            getline(ss, ts, ':');
            T task;
            task.id = stoi(id);
            task.status = status;
            task.ts = stoi(ts);
            
            if ( status == "start") {
                st.push(task);
            }else {
                auto curr = st.top();
                int t = task.ts - curr.ts + 1;
                timespent[curr.id] += t;
                st.pop();
                if (!st.empty()) {
                    timespent[st.top().id] -= t;
                }
                
                
            }
            
        
        }
        return timespent;
        
    }
};