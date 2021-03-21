/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:

Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

Output: "wertf"
Example 2:

Input:
[
  "z",
  "x"
]

Output: "zx"
Example 3:

Input:
[
  "z",
  "x",
  "z"
] 

Output: "" 

*/

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) {
            return words[0];
        }
        graph g = buildGraph(words);
        
       
        unordered_map<char, int> degrees = computeIndegrees(g);
        int numNodes = degrees.size();
        string order;
        queue<char> toVisit;
        for (auto node : degrees) {
            if (!node.second) {
                std::cout << "\n " << node.first;
                toVisit.push(node.first);
            }
        }
        for (int i = 0; i < numNodes; i++) {
            if (toVisit.empty()) {
                return "";
            }
            char c = toVisit.front();
            toVisit.pop();
            order += c;
            for (char neigh : g[c]) {
                if (!--degrees[neigh]) {
                    std::cout << "\n" << neigh << "::" << c;
                    toVisit.push(neigh);
                }
            }
        }
        return order;
    }
private:
    typedef map<char, unordered_set<char>> graph;
    
   /*
   //Find the first position where both chars are different (Becuase only the first one matters)
                //If (ab & ac) then (b&c) must be compared. Everything after that doesnt make sense
                //Because it can be abc and aca but it doesnt matter anymore
                //We did exit loop because we want to account later elements in map]
                
    */
    
    graph buildGraph(vector<string>& words) {
        graph g;
        int n = words.size();
        for (int i = 1; i < n; i++) {
            bool found = false;
            string word1 = words[i - 1], word2 = words[i];
            int m = word1.size(), n = word2.size(), l = max(m, n);
            for (int j = 0; j < l; j++) {
                if (j < m && g.find(word1[j]) == g.end()) {
                    g[word1[j]] = {};
                }
                if (j < n && g.find(word2[j]) == g.end()) {
                    g[word2[j]] = {};
                }
                if (j < m && j < n && word1[j] != word2[j] && !found)                  {
                    g[word1[j]].insert(word2[j]);
                    found = true;
                }
            }
        }
        return g;
    }
    
    unordered_map<char, int> computeIndegrees(graph& g) {
        unordered_map<char, int> degrees;
        for (auto adj : g) {
            degrees[adj.first];
            for (char neigh : adj.second) {
                degrees[neigh]++;
            }
        }
        return degrees;
    }
};