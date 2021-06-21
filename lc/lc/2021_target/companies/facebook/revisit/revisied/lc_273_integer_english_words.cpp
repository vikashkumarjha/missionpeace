/*
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: num = 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


 string parseAnswer(vector<string>& ans) {
        string tmp = "";
        for (int i = 0; i < ans.size(); i++) {
            if (i)
                tmp += " ";
            tmp += ans[i];
        }
        return tmp;
    }



string underThousand(string s) {

     string number[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string tys[10] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string tens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> ans;
        if (s == "000") {
            return number[0];
        }
        
        int s0 = s[0] - '0';
        int s1 = s[1] - '0';
        int s2 = s[2] - '0';
        
        if (s0 != 0)
            ans.push_back(number[s0] + " Hundred");
        
        if (s1 == 1)
            ans.push_back(tens[s2]);
        else if (s1 != 0)
            ans.push_back(tys[s1]);
        
        if (s2 != 0 && s1 != 1)
            ans.push_back(number[s2]);
        
        return parseAnswer(ans);



} 





string numberToWords(int num) {
    string suffix[] = {"", "Thousand", "Million", "Billon", "Trillion"};
    string s = to_string(num);
    vector<string> ans;
    while ( s.length() %3 != 0) {
        s = "0" + s;
    }
    if ( s == "000") {
        return "Zero";
    }

    for ( int i = 0; i < s.length(); i+= 3)
    {
        auto s1 = s.substr(i,3);
        string s2 = underThousand(s1);
        if ( s2 != "Zero") {
            s2 += suffix[(s.length() - i)/3 - 1];
            ans.push_back(s2);
        }
    }

    return parseAnswer(ans);


}



