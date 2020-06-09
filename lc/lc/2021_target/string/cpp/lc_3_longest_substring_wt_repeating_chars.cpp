#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
	if ( s.size() == 0 ) return 0;
	int l = 0;
	int r = 0;
	int n = s.length();
	int result = 0;
	unordered_map<char,int> m;
	for ( r; r < n; r++ ) {
		if ( m.count(s[r])) {
			l = max(l,m[s[r]]);
		}
		result = max(result, r - l + 1);
		m[s[r]] = r + 1;
	}
	return result;
        
}

int main()
{
	vector<string> input = { "abcd", "aaa", "abca", "abcxxxabcdefgh"};
	for ( auto s : input) {
		int r = lengthOfLongestSubstring(s);
		std::cout << "\n THe value of the result:" << r;

	}
	return 0;
}
