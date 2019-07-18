/*
方法二 动态规划 时间复杂度O(N2), 空间复杂度O(N2)

动态规划就是暴力法的进化版本，我们没有必要对每一个子串都重新计算，看看它是不是回文。我们可以记录一
些我们需要的东西，就可以在O（1）的时间判断出该子串是不是一个回文。这样就比暴力法节省了O（N）的时间复杂度 
哦，嘿嘿，其实优化很简单吧。

P（i，j）为1时代表字符串Si到Sj是一个回文，为0时代表字符串Si到Sj不是一个回文。

P（i，j）= P（i+1，j-1）（如果S[i] = S[j]）。这是动态规划的状态转移方程。

P（i，i）= 1，P（i，i+1）= 1 if（S[i]= S[i+1]）
*/

#include<iostream>
#include<string>

using namespace std;

string longestPalindromeDP(string s) {
	int n = s.length();
	int longestBegin = 0;
	int maxLen = 1;
	bool table[1000][1000] = { false };
	for (int i = 0; i < n; i++) {
		table[i][i] = true;   //前期的初始化
	}

	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			table[i][i + 1] = true; //前期的初始化
			longestBegin = i;
			maxLen = 2;
		}
	}

	for (int len = 3; len <= n; len++) {
		for (int i = 0; i < n - len + 1; i++) {
			int j = i + len - 1;
			if (s[i] == s[j] && table[i + 1][j - 1]) {
				table[i][j] = true;
				longestBegin = i;
				maxLen = len;
			}//if
		}//for2
	}//fo1

	return s.substr(longestBegin, maxLen);
}// longestPalindromeDP


int main(){
	string in;
	while (cin >> in){
		cout << endl << "longestPalindrome: " << longestPalindromeDP(in) << endl << endl;
	}//while
	return 0;
}