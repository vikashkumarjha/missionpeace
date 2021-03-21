class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> dict(begin(wordList), end(wordList));
        queue<string> q;
        q.push(beginWord);
        int ladderLength = 0;

        while (!q.empty()) {
            int qsize = q.size();
            ++ladderLength;
            while (qsize--){
                auto w = q.front(); q.pop();
                if ( w == endWord) 
                    return ladderLength;
                dict.erase(w);
                for ( int i = 0; i < w.size(); i++) {
                    char ch = w[i];
                    for ( int j = 0; j < 26; j++ ) {
                        w[i] = 'a' + j;
                        if ( dict.count(w)){
                            q.push(w);
                        } 
                    }
                    w[i] = ch;
                }
            }
        }
        return 0;

    }
};
