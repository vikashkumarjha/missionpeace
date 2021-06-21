/*
 *
 Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.*

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class TrieNode {
  public:
      bool isWord;
      unordered_map<char,TrieNode*> m;
      TrieNode() {
        isWord = false;
      }
};

class Trie {
  public:
    Trie() {}
    void add(string w)
    {
      TrieNode *curr = root;
      for ( auto c : w)
      {
        if (!curr->m.count(c))
        {
          curr->m.insert(make_pair(c, new TrieNode()));
        }
        curr = curr->m[c];
      }
      curr->isWord = true;
    }
    bool search(string w)
    {
      TrieNode *curr = root;
      for ( int i = 0; i < w.size(); i++)
      {
        if ( curr->m.count(w[i]))
        {
          curr = curr->m[w[i]];
        }
        else {
          return false;
        }
      }
      return ( curr && curr->isWord);

    }
    bool startsWith(string w)
    {
      return leaf(w);

    }


  private:
    TrieNode *root = new TrieNode();
    TrieNode *leaf(string w) 
    {
      TrieNode *curr = root;
      for (int i = 0; i < w.size() && curr; i++)
      {
        if ( curr->m.count(w[i])) {
          curr = curr->m[w[i]];
        }
        else 
        {
          return nullptr;
        }
      }
      return curr;
    }
};




class Solution {
  public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      if ( board.empty()) return {};

      Trie trie = Trie();
      for ( auto w : words)
        trie.add(w);

      int R = board.size();
      int C = board[0].size();
      vector<string> ans;

      for ( int i = 0; i < R ;i++)
      {
        for ( int j = 0; j < C; j++)
        {
          find(trie, board, ans, "", i, j);
          if ( ans.size() >= words.size())
            return ans;
        }

      }
      return ans;

    }

  private:
    void find(Trie &trie, vector<vector<char>> &b, vector<string> &res, string w, int i, int j)
    {
      int R = b.size();
      int C = b[0].size();
      if ( i >= 0 && i < R && j >= 0 && j < C && b[i][j])
      {
        w += b[i][j];
        if (!trie.startsWith(w)) return;

        if ( trie.search(w)) {
          res.push_back(w);
        }
        b[i][j] = 0;
        find(trie, b, res, w, i+1, j);
        find(trie, b, res, w, i-1, j);
        find(trie, b, res, w, i, j+1);
        find(trie, b, res, w, i, j-1);
        b[i][j] = w.back();
      }
    }

};



int main()
{
  Solution sol;
  vector<string> words = {"oath", "pea", "eat", "rain"};
  vector<vector<char>> board = {
    {'o', 'a', 'a', 'n'},
    {'e', 't', 'a', 'e'},
    {'i', 'h', 'k', 'r'},
    {'i', 'f', 'l', 'v'},

  };
  vector<string> res = sol.findWords(board, words);

  for_each(begin(res), end(res), [](string x) {
      cout << x << " ";

      });
  


  return 0;
}



/*



*/
