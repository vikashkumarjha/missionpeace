/*
Implement the StreamChecker class as follows:

StreamChecker(words): Constructor, init the data structure with the given words.
query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
 

Example:

StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
streamChecker.query('a');          // return false
streamChecker.query('b');          // return false
streamChecker.query('c');          // return false
streamChecker.query('d');          // return true, because 'cd' is in the wordlist
streamChecker.query('e');          // return false
streamChecker.query('f');          // return true, because 'f' is in the wordlist
streamChecker.query('g');          // return false
streamChecker.query('h');          // return false
streamChecker.query('i');          // return false
streamChecker.query('j');          // return false
streamChecker.query('k');          // return false
streamChecker.query('l');          // return true, because 'kl' is in the wordlist

*/
#include "../header.hpp"

class Trie{
  public:
    class TrieNode{
      public:
        vector<TrieNode*> children;
        bool endofword;
        TrieNode()
        {
            children.resize(26,NULL);
            endofword = false;
        }
    };
    
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string& word)
    {
        TrieNode* current = root;
        TrieNode* node;
        for(int i=0;i<word.size();i++)
        {
            if(current->children[word[i]-'a']==NULL)
            {
                node = new TrieNode();
                current->children[word[i]-'a'] = node;
            }
            
            current = current->children[word[i]-'a'];
        }
        
        current->endofword = true;
    }
    
    bool query(string& word)
    {
        TrieNode* current = root;
        for(int i=word.size()-1;i>=0;i--)
        {
            if(current->children[word[i]-'a']==NULL)
                return false;

            current = current->children[word[i]-'a'];
            if(current->endofword)
                return true;
        }
        
        return current->endofword;
    }
};
class StreamChecker {
public:
    Trie* trie;
    string str;
    StreamChecker(vector<string>& words) {
        trie = new Trie();
        str = "";
        for(auto i:words)
        {
            reverse(i.begin(),i.end());
            trie->insert(i);
        }
    }
    
    bool query(char letter) {
        str+=letter;
        return trie->query(str);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */