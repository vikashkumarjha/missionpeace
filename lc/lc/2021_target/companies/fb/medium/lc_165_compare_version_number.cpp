#include "header.hpp"
#include <sstream>
using namespace std;



/*
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1; if version1 < version2 return -1;otherwise
 * return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits
 * and the . character.
 *
 * The . character does not represent a decimal point and is used to separate
 * number sequences.
 *
 * For instance, 2.5 is not "two and a half" or "half way to version three", it
 * is the fifth second-level revision of the second first-level revision.
 *
 * You may assume the default revision number for each level of a version number
 * to be 0. For example, version number 3.4 has a revision number of 3 and 4 for
 * its first and second level revision number. Its third and fourth level
 * revision number are both 0.
 *
 * */

int compareVersion(string version1, string version2) {
    istringstream v1(version1);
    istringstream v2(version2);

    string num1,num2;

    while ( ! v1.eof() || !v2.eof())
    {
        if ( !v1.eof())
        {
            getline(v1,num1,'.');
        }else{
            num1 = "0";
        }
        if ( !v2.eof())
        {
            getline(v2,num2,'.');
        }else{
            num2 = "0";
        }
        int n1 = stoi(num1);
        int n2 = stoi(num2);

        if ( n1 == n2) continue;

        return ( n1 > n2 ? 1 : -1);

    }
    return 0;
}

int main() {
    string version1 = "1.001";
    string version2 = "1.0002";
    std::cout << "\n The result" << compareVersion(version1, version2);
    return 0;

}
