#include "header.hpp"
using namespace std;

int numJewelsInStones(string J, string S) {

    set<char> jSet(J.begin(), J.end());
    int count = 0;

    for ( auto c : S) {
        if ( jSet.count(c)) {
             ++count;
        }
    }
    return count;
}

int main() {
    string J = "aA", S = "aAAbbbb";
    std::cout << "\n The result: " << numJewelsInStones(J,S);



}
