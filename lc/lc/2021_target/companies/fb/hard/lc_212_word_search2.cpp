/*
 * Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



Example:

Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]


*/

#include "header.hpp"
using namespace std;

class TrieNode {
public:
    bool isWord;
    TrieNode *children[26];
    TrieNode() : isWord(false) {
        memset(children, 0, sizeof(children));
    }
}


class Trie {
public:
    Trie() {}

    void add(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node -> children[c - 'a']) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node->word = true;
    }

    bool search(string word) {
        TrieNode* node = leaf(word);
        if (node && node -> word) {
            node -> word = false;
            return true;
        }
        return false;
    }

    bool startsWith(string word) {
        return leaf(word);
    }
private:
    TrieNode* root = new TrieNode();

    TrieNode* leaf(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size() && node; i++) {
            node = node -> children[word[i] - 'a'];
        }
        return node;
    }
};



void find(Trie &trie, vector<vector<char> &b, int r , int c, string w, vector<string> &ans) {
    int R = b.size();
    int C = b[0].size();
    vector<vector<int>> DIRS = { {-1,0}, {0,1}, {0,-1}, {0,1}};
    if ( r >= 0 && r < C && c >= 0 && c < C && b[r][c]) {
        w += b[r][r];
        if ( !trie.startsWith(w)) {
            return;
        }
        if ( trie.search(w)) {
            ans.push_back(w);
        }
        b[i][j] = 0;

        for ( int k = 0; k < DIRS.size(); k++) {
            int x = r + DIRS[k][0];
            int y = c + DIRS[k][1];
            find(trie, b, x, y, w, ans);
        }

        b[i][j] = w.back();

    }
}


vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

    if ( board.empty()  ) return {};
    Trie trie = new Trie();

    for ( auto w : words) {
        trie.add(w);
    }

    int R = board.size();
    int C = R ? board[0].size() : 0;
    vector<string> ans;

    for ( int i = 0; i < R; i++) {
        for ( int j = 0; j < C; j++) {
            //we need the point and current word 
            find(trie, board, i, j, "", ans);
            if ( ans.size() >= words.size()) {
                return ans;
            }
        }
    }
    return ans;

}
