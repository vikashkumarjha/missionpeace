// Perform a walk on the trie and return the
// longest common prefix string


Time Complexity : Inserting all the words in the trie takes O(MN) time and performing a walk on the trie takes O(M) time, where-

N = Number of strings
M = Length of the largest string

int countChildren(struct TrieNode *node, int *index)
{
    int count = 0;
    for (int i=0; i<ALPHABET_SIZE; i++)
    {
        if (node->children[i] != NULL)
        {
            count++;
            *index = i;
        }
    }
    return (count);
}



string walkTrie(struct TrieNode *root)
{
    struct TrieNode *pCrawl = root;
    int index;
    string prefix;
  
    while (countChildren(pCrawl, &index) == 1 &&
            pCrawl->isLeaf == false)
    {
        pCrawl = pCrawl->children[index];
        prefix.push_back('a'+index);
    }
    return (prefix);
}



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0)
        {
            return "";
        }
        if (strs.size() == 1)
        {
            return strs[0];
        }
        string prefix = commonPrefix(strs[0], strs[1]);
        for (int i = 2; i < strs.size(); ++i)
        {
            prefix = commonPrefix(prefix, strs[i]);
        }
        return prefix;
    }
    
    string commonPrefix(const string& s1, const string& s2)
    {
        string prefix = "";
        for (int i = 0; i < s1.size() && s2.size(); ++i)
        {
            if (s1[i] == s2[i])
            {
                prefix += s1[i];
            }
            else
            {
                return prefix;
            }
        }
        return prefix;
    }
};
