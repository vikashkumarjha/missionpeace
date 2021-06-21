/*
You are given a string s, a split is called good if you can split s into 2 non-empty strings p and q where its concatenation is equal to s and the number of distinct letters in p and q are the same.

Return the number of good splits you can make in s.

 

Example 1:

Input: s = "aacaba"
Output: 2
Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.


The Idea is Create Suffix and Prefix Array with no of uniqe char Til That possition [ For That we can use Unordered_set ]
Then compair Prefix[i-1] whith suffix[i] Here i denote each inde of both array

Let's Tacke an example to understand It batter

	input = "acbadbaada"
                  " a  c  b  a  d  b  a  a  d  a "
    Pre Array  =   [1, 2, 3, 3, 4, 4, 4, 4, 4, 4]     ==>Pre_Array[pos] represent no of uniqe char til that point
    Suff Array =   [4, 4, 3, 3, 3, 3, 2, 2, 2, 1]     ==>Suff_Array[pos] represent no of uniqe char til that point count from backwords
        index       0  1  2  3  4  5  6  7  8  9
        
    Here Pre_Array[2] == suff_Array[3] and Pre_Array[3] == suff_Array[4]
    Hence answer would be = 2

    */
    
class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        vector<int>pre(s.length()),post(s.length());
        unordered_set<char>m1,m2;
        int l = s.length()-1;
        for(int i=0;i<s.length();i++){
            m1.insert(s[i]);
            m2.insert(s[l-i]);
            pre[i]    = m1.size();
            post[l-i] = m2.size();
        }
        for(int i=1;i<=l;i++)
            ans+=(pre[i-1]==post[i]);
        return ans;
    }
};


 bool goodSplit(vector<int> freqA, vector<int> freqB) {
	int a1 = 0, a2 = 0;
	for(int i = 0; i < 26; i++) {
		if(freqA[i])
			a1++;
		if(freqB[i]) 
			a2++;
	}

	return a1 == a2;
}
	
int numSplits(string s) {
	vector<int> freqA(26, 0), freqB(26, 0);
	int ans = 0;
	for(char ch : s)
		freqB[ch - 'a']++;

	for(char ch : s) {
		freqA[ch - 'a']++;
		freqB[ch - 'a']--;
		if(goodSplit(freqA, freqB))
			ans++;
	}

	return ans;
}
