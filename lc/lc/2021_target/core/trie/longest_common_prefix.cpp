#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
 
// Data structure to store a Trie node
struct Trie
{
    bool isLeaf;    // set when the node is a leaf node
    unordered_map<char, Trie*> character;
 
    // Constructor
    Trie() {
        isLeaf = false;
    }
};
 
// Iterative function to insert a string into a Trie
void insert(Trie* const &head, string const &str)
{
    // start from the root node
    Trie* curr = head;
 
    for (char ch: str)
    {
        // create a new node if the path doesn't exist
        if (curr->character.find(ch) == curr->character.end()) {
            curr->character[ch] = new Trie();
        }
 
        // go to the next node
        curr = curr->character[ch];
    }
 
    curr->isLeaf = true;
}
 
// Function to find the longest common prefix
string findLCP(string dict[], int n)
{
    // insert all keys into a Trie
    Trie* head = new Trie();
    for (int i = 0; i < n; i++) {
        insert(head, dict[i]);
    }
 
    // traverse the Trie and find the longest common prefix
 
    string lcp;
    Trie* curr = head;
 
    // loop until we find a leaf node or a node has more than 1 child
    while (curr && !curr->isLeaf && (curr->character.size() == 1))
    {
        // get an iterator to the only child
        auto it = curr->character.begin();
 
        // append current char to LCP
        lcp += it->first;
 
        // update `curr` pointer to the child node
        curr = it->second;
    }
 
    return lcp;
}
 
int main()
{
    // given set of keys
    string dict[] =
    {
        "code", "coder", "coding", "codable", "codec", "codecs", "coded",
        "codeless", "codependence", "codependency", "codependent",
        "codependents", "codes", "codesign", "codesigned", "codeveloped",
        "codeveloper", "codex", "codify", "codiscovered", "codrive"
    };
 
    // total number of keys
    int n = sizeof(dict)/sizeof(dict[0]);
 
    cout << "The longest common prefix is " << findLCP(dict, n);
 
    return 0;
}