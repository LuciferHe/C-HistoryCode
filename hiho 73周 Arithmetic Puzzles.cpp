
//题目：http://hihocoder.com/contest/hiho73/problem/1
//题解：http://hihocoder.com/discuss/question/2725/
//100
//A + B + C = AB
//1 + 0 + 9 = 10
//
//A + B + C = A + B
//1 + 2 + 0 = 1 + 2
//
//IOOOOOOOOOOOOOOOOOOOOOOOOO = IOOOOOOOOOOOOOOOOOOOOOOOOO
//10000000000000000000000000 = 10000000000000000000000000
//
//C = A
//Impossible!
//
//AB + CA + FG = DE + DG + BG
//12 + 31 + 78 = 45 + 48 + 28
//
//IH + G + FED + C + BA = A + BC + DEF + CZC
//79 + 5 + 634 + 2 + 10 = 0 + 12 + 436 + 282
//
//ZZZ + ABA = ZCA + ZAZ
//222 + 191 = 201 + 212


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
const double EPS = 1e-9;
const double OO = 1e15;
//const double PI = acos(-1.0); //M_PI; cmath
int vis[10];
int letter[26];
int countt;
string s, ts;
vector<string> Left;
vector<string> Right;
int maxLen;
int val[MAXN];


void printVector(){
	int i, j, k;
	for (i = 0; i < Left.size(); ++i){
		cout << Left[i] << " ";
	}
	cout << "\n\n";
	for (i = 0; i < Right.size(); ++i){
		cout << Right[i] << " ";
	}
}

void printVal(){
	int i, j, k;
	for (i = 0; i < 26; ++i){
		cout << i << ":" << val[i] << "  ";
	}
	cout << endl;
}

inline void init(){
	memset(letter, -1, sizeof(letter));
	mem(vis);
	mem(val);
	countt = 0;
	Left.clear();
	Right.clear();
	maxLen = 1;
}


bool check(){
	mem(val);
	int carry = 0;
	int i, j, k;
	int lenl = Left.size(), lenr = Right.size();
	for (i = 0; i < lenl; ++i){
		int lenNow = Left[i].length();
		for (j = 0; j < lenNow; ++j){
			val[lenNow - 1 - j] += letter[Left[i][j] - 'A'];
		}
	}

	for (i = 0; i < lenr; ++i){
		int lenNow = Right[i].length();
		for (j = 0; j < lenNow; ++j){
			val[lenNow - 1 - j] -= letter[Right[i][j] - 'A'];
		}
	}

	for (i = 0; i < maxLen; ++i){
		val[i + 1] += (val[i] / 10);
		val[i] %= 10;
		if (val[i]) return false;
	}
	if (val[i]) return false;

	return true;
}

bool dfs(int index){
	int start = letter[index];
	int i, j, k;
	if (index == 26){

		return check();
	}
	if (letter[index] == -1){
		return dfs(index + 1);
	}
	else{
		for (i = start; i < 10; ++i){
			if (vis[i] == 0){
				vis[i] = 1;
				letter[index] = i;
				if (dfs(index + 1)) return true;
				letter[index] = start;
				vis[i] = 0;
			}
		}
		return false;
	}//else
}

int main(){
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int i, j, k;
	bool isLeft;
	int n;
	string temps;
	cin >> n;
	getchar();
	while (n--){
		init();
		getline(cin, s);
		ts = s;
		k = 0;
		isLeft = true;
		for (i = 0; i < s.length(); ++i){
			if (isupper(s[i])){
				if (letter[s[i] - 'A'] == -1){
					++countt;
				}
				int tval = (i == 0 || ((s[i - 1] == '+' || s[i - 1] == '=') && (i != s.length() - 1 && isupper(s[i + 1])))) ? 1 : 0;
				if (letter[s[i] - 'A'] != 1) letter[s[i] - 'A'] = tval;
			}
			else{
				temps = s.substr(k, i - k);
				maxLen = maxLen > temps.length() ? maxLen : temps.length();
				if (isLeft){
					Left.push_back(temps);
					if (s[i] == '=') isLeft = false;
				}
				else{
					Right.push_back(temps);
				}
				k = i + 1;

			}
		}//for
		temps = s.substr(k, i - k);
		maxLen = maxLen > temps.length() ? maxLen : temps.length();
		Right.push_back(temps);

		if (countt <= 10 && dfs(0)){
			for (i = 0; i < ts.length(); ++i){
				if (isupper(ts[i])){
					ts[i] = '0' + letter[ts[i] - 'A'];
				}
			}//for
			cout << ts << "\n\n";
		}
		else{
			cout << "Impossible!\n\n";
		}
	}//while
	return 0;
}