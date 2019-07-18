/*
测试数据：
12
A+B+C=AB
A+B+C=A+B
IOOOOOOOOOOOOOOOOOOOOOOOOO=IOOOOOOOOOOOOOOOOOOOOOOOOO
C=A
ABC+C=ABD
ABCDEFGHIJK=K
DBA=DCA
AB+BA+CB+DB+EB+FB+GB+HB+IB+JB=AB+BA+CB+DB+EB+FB+GB+HB+IB+JB
A+B=A
AB+BC=DE
AB+C+D+EFGH=FGHI+HIJB
ABCDEFGHIJDEFGHDEFGHDEFGHDEFGHDEFGHDEFGH=ABCDEFGHIJDEFGHDEFGHDEFGHDEFGHDEFGHDEFGH


ANS:
1+0+9=10
1+2+0=1+2
10000000000000000000000000=10000000000000000000000000
No Solution
102+2=104
No Solution
No Solution
No Solution
1+0=1
12+24=36
12+0+4+9583=5837+3762
1023456789345673456734567345673456734567=102345678934567345673456734567345673456
7

题目：http://hihocoder.com/contest/hiho73/problem/1
题解：http://hihocoder.com/discuss/question/2725
*/

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cctype>
#include<map>
#include<algorithm>
using namespace std;

#define mem(a) memset(a, 0, sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define LETTER words[j][i]-'A'
const int MAXN = 100 + 5;
int vis[10];
int letterExist[26];
int val[26];
int notZero[26];
int kindCount;//出现的字母种类数
int m, n;//最大位数m，总共n个words
int leftCount, rightCount;
string s;
bool hasAns;
string ans;
vector<string> words;


struct Pos{
	int x, y;
	Pos(int xx = 0, int yy = 0) :x(xx), y(yy){}
	bool operator < (Pos const &A)const{
		return (x < A.x || (x == A.x && y < A.y));
	}
};

map<Pos, int> MP;

void scanAndPick(int i, int js, int je, int origin[26]){
	int arr[26] = { 0 };
	int j;
	for (j = js; j < je; ++j){
		int len = words[j].length();
		if (i < len){

			//BUG9
			if (origin[LETTER] > 0){
				if (arr[LETTER] >= origin[LETTER]){
					MP[Pos(i, j)] = LETTER;
				}
				else{
					MP[Pos(i, j)] = -1;
				}
				++arr[LETTER];
			}//如果左右有重复的字母

			else{
				MP[Pos(i, j)] = LETTER;
			}

		}//if  长度够

		else{
			MP[Pos(i, j)] = -1;
		}
	}
}

void pickUseless(){
	int i, j, k;
	int len;
	int myCount[2][26];

	for (i = 0; i < m; ++i){
		mem(myCount);
		for (j = 0; j < n; ++j){
			len = words[j].length();
			int index = (j < leftCount) ? 0 : 1;
			if (i < len){
				++myCount[index][LETTER];
			}
		}// 二层循环  遍历计数

		for (j = 0; j < 26; ++j){
			myCount[0][j] = MIN(myCount[0][j], myCount[1][j]);
		}
		scanAndPick(i, 0, leftCount, myCount[0]);
		scanAndPick(i, leftCount, n, myCount[0]);

	}//for  外层循环  0 --- m-1
}

void fillAndUpdateAns(){
	int i, j, k;
	string ts = s;
	int visCopy[10];//BUG10
	int valCopy[26];//BUG10
	memcpy(visCopy, vis, sizeof(vis));
	memcpy(valCopy, val, sizeof(val));

	for (i = 0; i < ts.length(); ++i){
		if (isupper(ts[i])){
			int letter = ts[i] - 'A';
			if (valCopy[letter] == -1){
				for (j = 0; j < 10; ++j){
					if (!visCopy[j]){
						if (j == 0 && notZero[letter]) { continue; }
						visCopy[j] = 1;
						valCopy[letter] = j;
						break;
					}
				}
				if (j == 10){//BUG11
					return;
				}
			}//如果之前没被赋值

			ts[i] = '0' + valCopy[letter];
		}//isUpper
	}//for


	if (!hasAns){
		ans = ts;
		hasAns = true;
		return;
	}
	
	ans = MIN(ans, ts);
	return;
}

inline void init(){
	memset(val, -1, sizeof(val));
	mem(vis);
	mem(notZero);
	mem(letterExist);
	kindCount = 0;
	words.clear();
	MP.clear();
	hasAns = false;
	ans = "";
	m = 1;
	n = 1;
	leftCount = 0;
	rightCount = 0;
}


int op(int j){
	if (j < leftCount) return 1;
	return -1;
}


//从0开始
void dfs(int i, int j, int s) {
	if (i == m){
		if (s == 0){
			fillAndUpdateAns();
		}
		return;
	}

	if (j == n){
		if (s % 10 == 0){
			dfs(i + 1, 0, s / 10);//BUG7
		}
		return;//BUG6
	}

	int letter = MP[Pos(i, j)];
	if (letter == -1){
		dfs(i, j + 1, s);
		return;
	}

	if (val[letter] != -1){
		dfs(i, j + 1, s + val[letter] * op(j));
	}
	else{
		int startNum = 0;
		if (notZero[letter]){
			startNum = 1;
		}
		int k = 0;
		for (k = startNum; k < 10; ++k){
			if (!vis[k]){
				vis[k] = 1;
				val[letter] = k;
				dfs(i, j + 1, s + val[letter] * op(j));
				val[letter] = -1;
				vis[k] = 0;
			}
		}
	}
}//dfs


string reverse(string s){
	string tempStr = s;
	int len = s.length();
	if (len <= 1) return tempStr;//BUG4
	for (int i = 0; i < len; ++i){
		tempStr[i] = s[len - 1 - i];
	}
	return tempStr;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int i, j, k;
	bool isLeft;
	int cas;
	cin >> cas;
	getchar();
	while (cas--){
		init();
		getline(cin, s);
		k = 0;
		isLeft = true;
		string temps;
		for (i = 0; i < s.length(); ++i){
			if (isupper(s[i])){
				if (letterExist[s[i] - 'A'] == 0){
					++kindCount;//BUG3
					letterExist[s[i] - 'A'] = 1;
				}
			}
			else{
				temps = reverse(s.substr(k, i - k));
				int lenTemps = temps.length();
				if (lenTemps > 1){
					notZero[temps[lenTemps - 1] - 'A'] = 1;
				}
				m = MAX(m, lenTemps);
				if (isLeft){
					++leftCount;
					if (s[i] == '=') isLeft = false;
				}
				else{
					++rightCount;
				}
				words.push_back(temps);
				k = i + 1;

			}//else

		}//for 遍历每一字符

		temps = reverse(s.substr(k, i - k));
		int lenTemps = temps.length();
		if (lenTemps > 1){
			notZero[temps[lenTemps - 1] - 'A'] = 1;
		}
		m = MAX(m, lenTemps);
		words.push_back(temps);
		++rightCount;//BUG1


		n = leftCount + rightCount;//计算words总个数

		if (kindCount <= 10){
			pickUseless();
			dfs(0, 0, 0);

			if (hasAns){
				cout << ans << endl;
			}
			else{
				cout << "No Solution\n";
			}
		}
		else{
			cout << "No Solution\n";
		}
	}//while
	return 0;
}