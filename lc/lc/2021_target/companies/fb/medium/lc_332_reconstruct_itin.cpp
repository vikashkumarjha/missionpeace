/*
 * Given a list of airline tickets represented by pairs of departure and arrival
 * airports [from, to], reconstruct the itinerary in order. All of the tickets
 * belong to a man who departs from JFK. Thus, the itinerary must begin with
 * JFK.
 *
 * Note:
 *
 * If there are multiple valid itineraries, you should return the itinerary that
 * has the smallest lexical order when read as a single string. For example, the
 * itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
 * All airports are represented by three capital letters (IATA code).
 * You may assume all tickets form at least one valid itinerary.
 * Example 1:
 *
 * Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
 *
 * */

#include "header.hpp"
using namespace std;
// first we will build the graph
unordered_map<string, multiset<string>> G;
vector<string> route;

void treeDFS(string s) {
    while ( !G[s].empty() ) {
        auto curr = *G[s].begin();
        // we cannot visit same edge twice
        G[s].erase(G[s].begin());
        treeDFS(curr);
    }
    route.push_back(s);
}

vector<string> findItinerary(vector<vector<string>> & tickets) {

    for ( auto t : tickets) {
        G[t[0]].insert(t[1]);
    }

    string startinPoint = "JFK";
    treeDFS(startinPoint);
    return vector<string>(route.rbegin(), route.rend());

}

int main() {

    vector<vector<string>> tickets = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}
    };

    vector<string> itin = findItinerary(tickets);
    std::for_each(itin.begin(), itin.end(),[](string x){ std::cout << x << " ";});

}
