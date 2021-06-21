/*
Given a url startUrl and an interface HtmlParser, implement a web crawler to crawl all links that are under the same hostname as startUrl. 

Return all urls obtained by your web crawler in any order.

Your crawler should:

Start from the page: startUrl
Call HtmlParser.getUrls(url) to get all urls from a webpage of given url.
Do not crawl the same link twice.
Explore only the links that are under the same hostname as startUrl.
*/


/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> res;
        unordered_set<string> visited;
        dfs(getHostname(startUrl), startUrl, htmlParser, res, visited);
        return res;
    }
    
    void dfs(const string& hostname, const string& start, HtmlParser& htmlParser, vector<string>& res, unordered_set<string>& visited){
        if(visited.count(start)) return;
        visited.insert(start);
        if(getHostname(start) != hostname) return;
        res.push_back(start);
        for(const auto& s:htmlParser.getUrls(start))
            dfs(hostname, s, htmlParser, res, visited);
    }
    
    string getHostname(const string& url)
    {
        auto s = url.substr(7);
        auto pos1 = s.find('/'), pos2 = s.find(':');
        if(pos1 == string::npos && pos2 == string::npos) return s;
        else return s.substr(0, min(pos1, pos2));
    }
};