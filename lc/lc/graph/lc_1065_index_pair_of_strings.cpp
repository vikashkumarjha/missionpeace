/*
Given a text string and words (a list of strings), return all index pairs [i, j] so that the substring text[i]...text[j] is in the list of words.

 

Example 1:

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]
Example 2:

Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: 
Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].



// we can use the trie to minimize

*/


class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        for ( auto w : words) {
            int pos = text.find(w);
            while ( pos != string::npos) {
                res.push_back({pos, pos + int(w.size()) - 1});
                pos = text.find(w, pos + 1);
            }
        }
        
        sort(begin(res), end(res));
        return res;
    }
};



class Solution {
public:
    struct Node
    {
        vector<Node*>children;
        bool isEnd;
        Node()
        {
            children=vector<Node*>(26,NULL);
            isEnd=false;
        }
    };
    void insert(Node *root,string word)
    {
        Node *temp=root;
        for(int i=0;i<word.size();i++)
        {
            int index=word[i]-'a';
            if(temp->children[index]==NULL)
            {
                temp->children[index]=new Node();
            }
            temp=temp->children[index];
        }
        temp->isEnd=true;
    }
    vector<vector<int>> indexPairs(string text, vector<string>& words)
    {
        Node *root=new Node();
        for(int i=0;i<words.size();i++)
        {
            insert(root,words[i]);
        }
        vector<vector<int>>res;
        for(int i=0;i<text.size();i++)
        {
            Node *temp=root;
            for(int j=i;j<text.size();j++)
            {
                temp=temp->children[text[j]-'a'];
                if(temp!=NULL&&temp->isEnd==true)
                    res.push_back({i,j});
                if(temp==NULL)
                    break;
            }
        }
        return res;
    }
};