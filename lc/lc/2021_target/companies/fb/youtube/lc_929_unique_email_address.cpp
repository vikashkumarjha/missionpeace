#include "header.hpp"
using namespace std;


int numUniqueEmails(vector<string>& emails) {
    set<string> uniqueEmails;
    for ( auto e : emails) {
        auto pos = e.find('@');
        if ( pos != string::npos) {
            auto localName = e.substr(0, pos);
            auto domain = e.substr(pos+1);
            pos = localName.find('.');
            while ( pos != string::npos) {
                localName.erase(pos, 1);
                pos = localName.find('.', pos + 1);
            }

            pos = localName.find('+');
            if ( pos != string::npos) {
                localName = localName.substr(0, pos);
            }
            uniqueEmails.insert(localName + "@" + domain);
        }

    }
    return uniqueEmails.size();
}

int main() {
    vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    std::cout << "\n Unique emails" << numUniqueEmails(emails);
    return 0;
}
