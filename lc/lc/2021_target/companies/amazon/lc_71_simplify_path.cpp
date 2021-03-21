/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period '.' refers to the current directory. Furthermore, a double period '..' moves the directory up a level.

Note that the returned canonical path must always begin with a slash '/', and there must be only a single slash '/' between two directory names. The last directory name (if it exists) must not end with a trailing '/'. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: path = "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: path = "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.


*/

class Solution {
public:
    string simplifyPath(string path) {
        string result, tmp;
        vector<string> s;
       
        stringstream ss(path);
        char delim = '/';
       
        while (getline(ss, tmp, delim)) {
            if (tmp == "" || tmp == ".")
                continue;
           
            if (tmp == ".." && !s.empty())
                s.pop_back();
            else if (tmp != "..")
                s.push_back(tmp);
        }
       
       
        for (const auto str : s)
             result += "/" + str;
       
       
        return result.empty() ? "/" : result;
    }
};
