/*Given a file and assume that you can only read the file using a given method read4, implement a method read to read n characters. Your method read may be called multiple times.

 

Method read4:

The API read4 reads 4 consecutive characters from the file, then writes those characters into the buffer array buf.

The return value is the number of actual characters read.

Note that read4() has its own file pointer, much like FILE *fp in C.

*/

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    int p = 4;
    int i = 4;
    char tmp[4];
public:
    int read(char *buf, int n) {
        int sum = 0;
        while(sum < n){
            if(p == i){
                i = read4(tmp);
                p = 0;
            }
            if(i == 0) break;
            *buf++ = tmp[p++];
            sum++;
        }
        return sum;
    }
};