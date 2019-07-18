#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<unordered_set>


#include<algorithm>
using namespace std;

class Solution {
public:
	void breakWord(vector<string> &res, string &s, unordered_set<string> &wordDict, string str, int idx, vector<bool> &dp) {
		string substr;
		for (int len = 1; idx + len < s.length() + 1; ++len) {
			if (dp[idx + len] && wordDict.count(s.substr(idx, len)) > 0) {
				substr = s.substr(idx, len);
				if (idx + len < s.length()) {
					breakWord(res, s, wordDict, str + substr + " ", idx + len, dp);
				}
				else {
					res.push_back(str + substr);
					return;
				}
			}//if
		}//for
	}//breakWord

	vector<string> wordBreak(string s, unordered_set<string> &wordDict) {
		vector<bool> dp(s.length() + 1, false);// s.length() + 1 个值为false的vector 
		dp[0] = true;
		for (int i = 0; i < s.length(); ++i) {
			if (dp[i]) {
				for (int len = 1; i + len < s.length() + 1; ++len) {
					if (wordDict.count(s.substr(i, len)) > 0) {
						dp[i + len] = true;
					}
				}
			}//if
		}//for
		vector<string> res;
		if (dp[s.length()])
			breakWord(res, s, wordDict, "", 0, dp);
		return res;
	}
};

int main(){
	return 0;
}