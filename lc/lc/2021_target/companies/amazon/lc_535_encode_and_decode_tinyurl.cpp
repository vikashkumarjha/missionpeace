/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL 
can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

*/


#include "header.hpp"


class Solution {
public:

    std::unordered_map<string, string> myMap;
    long long key = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        std::stringstream ss;
        ss << to_string(++key);
        long long hexKey;
        ss >> std::hex >> hexKey;
        string shortUrl = string("http://tinyurl.com/") + to_string(hexKey);
        myMap[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto iter = myMap.find(shortUrl);
        if(iter != myMap.end())
            return iter -> second;
        return "";
    }
};s

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));