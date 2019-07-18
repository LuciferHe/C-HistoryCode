//时间复杂度 n^2   空间复杂度 n
/*
这个算法思想其实很简单啊，时间复杂度为O（N2），空间复杂度仅为O（1）。就是对给定的字符串S，分别以该字符串S中的每一个字符C为中心，向两边扩展，记录下以字符C为中心的回文子串的长度。但是有一点需要注意的是，回文的情况可能是 a b a，也可能是 a b b a。
*/
#include<iostream>
#include<string>
using namespace std;

string extend(string s, int a, int b, int n){
	int l = a, r = b;
	while (0<= l && r<n && s[l] == s[r]){
		--l; ++r;
	}
	return s.substr(l+1,r-l-1);
}

string longestPalindrome(string s) {
	int len = s.size();
	if (len == 0) return "";
	string ans = s.substr(0,1);//First char
	int i, j;
	for (i = 0; i < len-1; ++i){
		string p1 = extend(s, i, i, len);
		if (p1.length() > ans.length()) ans = p1;
		string p2 = extend(s, i, i+1, len);
		if (p2.length() > ans.length()) ans = p2;
	}
	return ans;
}

int main(){
	string in;
	while (cin >> in){
		cout << longestPalindrome(in);
	}
	return 0;
}