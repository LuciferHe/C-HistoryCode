//这组测试数据会超时
//ABCDEFJHIJJJJJJJJJJJJJJJJJAAAA=ABCDEFJHIJJJJJJJJJJJJJJJJJAAAA
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
#define DEBUG 0
#define DEBUG1 0
#define DEBUG2 0

#define mem(a) memset(a, 0, sizeof(a))
//for i [0,n)
#define For(i,n) for(i=0;i<n;++i)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
const int MAXN = 100 + 5;
//const double PI = acos(-1.0); //M_PI; cmath
int vis[10];
int letterVis[26];
int val[26];
int notZero[26];
int kindCount;//出现的字母种类数
int m, n;//最大位数m，总共n个word
int leftCount, rightCount;
string s;
string ans;
vector<string> word;


void fillAndUpdateAns(){
	int i, j, k;
	string ts = s;
	int start = 0;
	for (i = 0; i < s.length(); ++i){
		if (isupper(s[i])){
			if (val[s[i] - 'A'] == -1){
				for (j = start; j < 10; ++j){
					if (!vis[j]){
						vis[j] = 1;
						val[s[i] - 'A'] = j;
						ts[i] = '0' + j;
						start = j + 1;
						break;
					}
				}
			}
			else{
				ts[i] = '0' + val[ts[i] - 'A'];
			}
		}//if isupper
	}//for

	if (ans.compare("No Solution") == 0){
		ans = ts;
	}
	else{
		ans = MIN(ans, ts);
	}

	return;

}

inline void init(){
	memset(val, -1, sizeof(val));
	mem(vis);
	mem(notZero);
	mem(letterVis);
	kindCount = 0;
	word.clear();
	ans = "No Solution";
	m = 1;
	n = 1;
	leftCount = 0;
	rightCount = 0;
}


int getLetter(int i, int j){//word[j][i]  BUG5
	int len = word[j].length();
	if (i < len){//BUG2
		return word[j][i] - 'A';
	}
	return -1;
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

	int letter = getLetter(i, j);

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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int i, j, k;
	bool isLeft;
	int cas;
	string temps;
	cin >> cas;
	getchar();
	while (cas--){
		init();
		getline(cin, s);
		k = 0;
		isLeft = true;
		for (i = 0; i < s.length(); ++i){
			if (isupper(s[i])){
				if (letterVis[s[i] - 'A'] == 0){
					++kindCount;//BUG3
					letterVis[s[i] - 'A'] = 1;
				}
				int tcal = (i == 0 || ((s[i - 1] == '+' || s[i - 1] == '=') && (i != s.length() - 1 && isupper(s[i + 1])))) ? 1 : 0;
				if (!notZero[s[i] - 'A']) notZero[s[i] - 'A'] = tcal;
			}
			else{
				temps = reverse(s.substr(k, i - k));
				m = MAX(m, temps.length());
				if (isLeft){
					++leftCount;
					if (s[i] == '=') isLeft = false;
				}
				else{
					++rightCount;
				}
				word.push_back(temps);
				k = i + 1;

			}
		}//for
		temps = reverse(s.substr(k, i - k));
		m = MAX(m, temps.length());
		word.push_back(temps);
		++rightCount;//BUG1
		n = leftCount + rightCount;//计算word总个数

		if (kindCount <= 10){
			dfs(0, 0, 0);
			cout << ans << "\n";
		}
		else{
			cout << "No Solution\n";
		}
	}//while
	return 0;
}