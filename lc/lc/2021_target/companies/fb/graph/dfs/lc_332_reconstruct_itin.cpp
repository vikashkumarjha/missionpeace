#include "header.hpp"
#include <multiset>
using namespace std;


 vector<string, multiset<string>> G;
 vector<string> result;

 void treeDFS(string port) {
     while (!G[port].empty()) {
         string x = *G[port].begin(); G[port].erase(G[port].begin()); //lexicographi
         treeDFS(x);
     }
     result.push_back(port);
 }

 vector<string> findItinerary(vector<vector<string>> & tickets) {
     // build the graph
    for ( const auto &t : tickets ) {
        G[t[0]].insert(t[1]);
    }
    sting x = "JFK";
    treeDFS(x);
    return vector<string>(result.rbegin(), result.rend());

 }



class Solution 
{
private: 
    unordered_map<string, multiset<string>> myGraph;
    vector<string> route;
    void visit(string port) //DFS traversal to retrieve the route;
    {
        //If k does not match the key of any element in the container, the function inserts a 
        //new element with that key and returns a reference to its mapped value. Notice that 
        //this always increases the container size by one, even if no mapped value is assigned 
        //to the element (the element is constructed using its default constructor).
        while(myGraph[port].size()) //the port exists in myGraph and there are others it can reach;
        {
            string next = *myGraph[port].begin(); //retrieve the next from the beginning position to ensure lexical order;
            myGraph[port].erase(myGraph[port].begin()); //once visited, erase it;
            visit(next); //move to the next;
        }
        route.push_back(port); //add the destinations first and then the source;
    }
public:
    //AC - 48ms;
    vector<string> findItineraryRecursive(vector<pair<string, string>> tickets)
    {
        for(auto& ticket: tickets) //constructing the graph;
            myGraph[ticket.first].insert(ticket.second);
        visit("JFK"); //start from JFK;
        return vector<string>(route.rbegin(), route.rend()); //reverse the route to the get the sequence;
    }

    //AC - 40ms;
    vector<string> findItineraryIterative(vector<pair<string, string>> tickets) 
    {
        unordered_map<string, multiset<string>> myGraph;
        int i, n = tickets.size();
        string first, second;
        for(auto &ticket: tickets) //constructing the graph;
            myGraph[ticket.first].insert(ticket.second);
        vector<string> marching;
        vector<string> itinerary;
        marching.push_back("JFK");
        while(marching.size()>0) //all tickets are to be used though there might be different lexical orders;
        {
            string from = marching.back();
            if(myGraph.count(from)) //not the final destination, push it to the stack;
            {
                multiset<string>& to = myGraph[from]; //multiset will sort the strings automatically;
                marching.push_back(*to.begin());
                to.erase(to.begin());
                if(to.empty()) myGraph.erase(from); //once the place has not any destinations more, delete it from the graph;
            }
            else
            {
                itinerary.push_back(from); //the destination - so far;
                marching.pop_back(); //delete from the stack;
            }
        }
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};