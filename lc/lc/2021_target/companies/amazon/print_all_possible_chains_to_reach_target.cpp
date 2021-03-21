// C++ Program to implememnt 
// the above approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to print all possible shortest 
// sequences starting from start to target. 
void displaypath(vector<vector<string> >& res) 
{ 
    for (int i = 0; i < res.size(); i++) { 
        cout << "[ "; 
        for (int j = 0; j < res[0].size(); j++) { 
            cout << res[i][j] << ", "; 
        } 
        cout << " ]\n"; 
    } 
} 
// Find words differing by a single 
// character with word 
vector<string> addWord( 
    string word, 
    unordered_set<string>& dict) 
{ 
    vector<string> res; 
  
    // Find next word in dict by changing 
    // each element from 'a' to 'z' 
    for (int i = 0; i < word.size(); i++) { 
        char s = word[i]; 
        for (char c = 'a'; c <= 'z'; c++) { 
            word[i] = c; 
            if (dict.count(word)) 
                res.push_back(word); 
        } 
        word[i] = s; 
    } 
    return res; 
} 
  
// Function to get all the shortest possible 
// sequences starting from 'start' to 'target' 
vector<vector<string> > findLadders( 
    vector<string>& Dict, 
    string beginWord, 
    string endWord) 
{ 
    // Store all the shortest path. 
    vector<vector<string> > res; 
  
    // Store visited words in list 
    unordered_set<string> visit; 
  
    // Queue used to find the shortest path 
    queue<vector<string> > q; 
  
    // Stores the distinct words from given list 
    unordered_set<string> dict(Dict.begin(), 
                               Dict.end()); 
    q.push({ beginWord }); 
  
    // Stores whether the shortest 
    // path is found or not 
    bool flag = false; 
  
    while (!q.empty()) { 
        int size = q.size(); 
        for (int i = 0; i < size; i++) { 
  
            // Explore the next level 
            vector<string> cur = q.front(); 
            q.pop(); 
            vector<string> newadd; 
  
            // Find words differing by a 
            // single character 
            newadd = addWord(cur.back(), dict); 
  
            // Add words to the path. 
            for (int j = 0; j < newadd.size(); j++) { 
                vector<string> newline(cur.begin(), 
                                       cur.end()); 
  
                newline.push_back(newadd[j]); 
  
                // Found the target 
                if (newadd[j] == endWord) { 
                    flag = true; 
                    res.push_back(newline); 
                } 
  
                visit.insert(newadd[j]); 
                q.push(newline); 
            } 
        } 
  
        // If already reached target 
        if (flag) { 
            break; 
        } 
  
        // Erase all visited words. 
        for (auto it : visit) { 
            dict.erase(it); 
        } 
  
        visit.clear(); 
    } 
    return res; 
} 
  
// Driver Code 
int main() 
{ 
    vector<string> str{ "ted", "tex", "red", 
                        "tax", "tad", "den", 
                        "rex", "pee" }; 
    string beginWord = "red"; 
    string endWord = "tax"; 
  
    vector<vector<string> > res 
        = findLadders(str, beginWord, endWord); 
  
    displaypath(res); 
} 
