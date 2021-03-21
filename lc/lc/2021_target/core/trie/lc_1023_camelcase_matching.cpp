/*
A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

 

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".

*/

struct Node
{
    Node* children[52] = {NULL};
    bool isWord;
    Node() {
        for ( int i = 0; i < 52; i++){
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class Solution {
public:
    Node* root = new Node();
    void insertTrie(string pattern)
    {
        Node* ptr = root;
        for(int i=0; i<pattern.size(); i++)
        {
            if(pattern[i] >= 'a' && pattern[i] <= 'z')
            {
                if(ptr->children[pattern[i] - 'a'] == nullptr)
                    ptr->children[pattern[i] - 'a'] = new Node();
                ptr = ptr->children[pattern[i]-'a'];
            }
            else
            {
                if(ptr->children[pattern[i] - 'A' + 26] == nullptr)
                    ptr->children[pattern[i] - 'A' + 26] = new Node();
                ptr = ptr->children[pattern[i] - 'A' + 26];
            }
        }
        
        ptr->isWord = true;
    }
    
    bool findInTrie(string q)
    {
        Node* ptr = root;
        for(int i=0; i<q.size(); i++)
        {
            // for lower case be liberal.
            if(q[i] >= 'a' && q[i] <= 'z')
            {
                if(ptr->children[q[i]-'a'] != nullptr)
                    ptr = ptr->children[q[i]-'a'];
            }
            else
            {
                if(ptr->children[q[i] - 'A' + 26] == nullptr)
                   return false;
                ptr = ptr->children[q[i] - 'A' + 26];
            }
        }
        
        return (ptr->isWord);
    }
    
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        insertTrie(pattern);
        for(auto& q : queries)
            res.push_back(findInTrie(q));
        return res;
    }
};