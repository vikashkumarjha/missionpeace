class Solution {
public:
    bool isValidIPV4Block(string & str) {
         if (str.empty() || str.size() >= 4)
            return false;
       
         for (int i = 0; i < str.size(); i++)
              if (!isdigit(str[i]) || (i == 0 && str[i] == '0' && str.size() > 1 ))
                  return false;

         return  stoi(str) <= 255;
    }
     
    const string validIPV6Chars = "0123456789abcdefABCDEF";
   
    bool isValidIPV6Block(string & str) {
        if (str.empty() || str.size() >= 5)
            return false;
           
     for (int i = 0; i < str.size(); i++)
        if (validIPV6Chars.find(str[i]) == string::npos)
            return false;
   
        return true;
    }    
   
   
    string validIPAddress(string IP) {
        vector<string> output = {"IPv4", "IPv6", "Neither"};
        stringstream ss(IP);
        string word;
        char delim = '.';
       
        if (IP.substr(0, 4).find('.') != string::npos) {
            for (int i = 0; i < 4; i++)
                if (!getline(ss, word, delim) || !isValidIPV4Block(word))
                    return output[2];
           
            return ss.eof() ? output[0] : output[2];
        }
        else if (IP.substr(0, 5).find(':') != string::npos)
        {
            delim = ':';
            for (int i = 0; i < 8; i++)
                 if (!getline(ss, word, delim) || !isValidIPV6Block(word))
                     return output[2];
           
            return ss.eof()? output[1] : output[2];
        }
        else
        {
             return output[2];
        }
    }
};
