/*

题目：http://hihocoder.com/problemset/problem/1061
题解：原创
类型:字符串简单处理
#1061 : Beautiful String
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
We say a string is beautiful if it has the equal amount of 3 or more continuous letters (in increasing order.)

Here are some example of valid beautiful strings: "abc", "cde", "aabbcc", "aaabbbccc".

Here are some example of invalid beautiful strings: "abd", "cba", "aabbc", "zab".

Given a string of alphabets containing only lowercase alphabets (a-z), output "YES" if the string contains a beautiful sub-string, otherwise output "NO".

输入
The first line contains an integer number between 1 and 10, indicating how many test cases are followed.

For each test case: First line is the number of letters in the string; Second line is the string. String length is less than 10MB.

输出
For each test case, output a single line "YES"/"NO" to tell if the string contains a beautiful sub-string.

提示
Huge input. Slow IO method such as Scanner in Java may get TLE.

样例输入
5
3
abc
4
aaab
6
abccde
3
abb
6
aabbcc
样例输出
YES
NO
YES
NO
YES
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


#define mem(a) memset(a, 0, sizeof(a))
const int MAXN = (1 << 24) + 5;

struct Node{
	int x, y;//x:ASCII y:count
	Node(int xx = 0, int yy = 0) :x(xx), y(yy){}
};

char s[MAXN];
vector<Node> V;
int cas, len, ct;

inline void init(){
	ct = 0;
	mem(s);
	V.clear();
}

int main(){
	int i, j, t = 0;
	scanf("%d",&cas);
	while (t++ < cas){
		init();
		scanf("%d%s",&len,s);
		int a, ii, f2=0;//f2=0 表示NO
		for (i = 0; i < len;){
			if (i == 0) a = s[0];
			ii = i;//最后的值是i-ii i表示下一个字母的位置
			int f1 = 0;//表示  数组未越界
			while (i<len){
				if (s[i] != a) break;
				++i;
				if (i == len) f1 = 1;
			}//遇到不同字母 跳出

			if (f1){ 
				V.push_back(Node(a,len-ii)); 
			}
			else{
				V.push_back(Node(a, i - ii));
				a = s[i];
			}
			++ct;

			//进行判断
			if (ct>2 && V[ct - 2].y <= V[ct-1].y && V[ct - 2].y <= V[ct-3].y && V[ct - 2].x + 1 == V[ct-1].x && V[ct - 3].x + 2 == V[ct-1].x){
				f2 = 1;
				printf("YES\n");
				break;
			}//符合条件
		}//遍历 s

		if (!f2){
			printf("NO\n");
		}
	}//while
	return 0;
}