
//这组测试数据会超时
//ABCDEFJHIJJJJJJJJJJJJJJJJJAAAA=ABCDEFJHIJJJJJJJJJJJJJJJJJAAAA
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cctype>
#include<map>
#include<algorithm>
using namespace std;
#define DEBUG 0
#define DEBUG1 0
#define DEBUG2 0
#define DEBUG3 0
#define DEBUG4 0
#define DEBUG5 0
#define DEBUG6 0

#define mem(a) memset(a, 0, sizeof(a))
//for i [0,n)
#define For(i,n) for(i=0;i<n;++i)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define CurrentLetter word[j][i]-'A'
const int MAXN = 100 + 5;
int vis[10];
int letterExist[26];
int val[26];
int finalVal[26];
int notZero[26];
int kindCount;//出现的字母种类数
int m, n;//最大位数m，总共n个word
int leftCount, rightCount;
string s;
int hasAns;
vector<string> word;


struct Pos{
	int x, y;
	Pos(int xx = 0, int yy = 0) :x(xx), y(yy){}
	bool operator < (Pos const &A)const{
		return (x < A.x || (x == A.x && y < A.y));
	}
};

map<Pos, int> MP;

void printMap(){
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			cout << MP[Pos(i, j)] << " ";
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
}



void pickUseless(){
	int i, j, k;
	int len;
	int myCount[2][26];

	for (i = 0; i < m; ++i){
		mem(myCount);

		for (j = 0; j < n; ++j){
			len = word[j].length();
			int index = (j < leftCount) ? 0 : 1;
			if (i < len){
				++myCount[index][CurrentLetter];
			}
		}// 二层循环  遍历计数

		/*	if (DEBUG5){
				cout << "\nmyCount " << i << " :\n";
				for (j = 0; j < 26; ++j){
				cout << myCount[0][j] << " ";
				}
				cout << "\n\n";
				for (j = 0; j < 26; ++j){
				cout << myCount[1][j] << " ";
				}
				cout << "\n\n";
				}*/

		for (j = 0; j < 26; ++j){
			myCount[0][j] = MIN(myCount[0][j], myCount[1][j]);
		}

		//if (DEBUG3){
		//	cout << "\nmyCount " << i << " :\n";
		//	for (j = 0; j < 26; ++j){
		//		cout << myCount[0][j] << " ";
		//	}
		//	cout << "\n\n";
		//	for (j = 0; j < 26; ++j){
		//		cout << myCount[1][j] << " ";
		//	}
		//}


		//下面可以放到一个函数里
		mem(myCount[1]);

		//if (DEBUG3){
		//	cout << "\nmyCount " << i << " :\n";
		//	for (j = 0; j < 26; ++j){
		//		cout << myCount[0][j] << " ";
		//	}
		//	cout << "\n\n";
		//	for (j = 0; j < 26; ++j){
		//		cout << myCount[1][j] << " ";
		//	}
		//}
		for (j = 0; j < leftCount; ++j){
			len = word[j].length();
			if (i < len){

				//BUG9
				if (myCount[0][CurrentLetter] > 0){
					if (myCount[1][CurrentLetter] >= myCount[0][CurrentLetter]){
						MP[Pos(i, j)] = CurrentLetter;
					}
					else{
						MP[Pos(i, j)] = -1;
					}
					++myCount[1][CurrentLetter];
				}//如果左右有重复的字母

				else{
					MP[Pos(i, j)] = CurrentLetter;
				}

			}//if  长度够

			else{
				MP[Pos(i, j)] = -1;
			}
		}

		mem(myCount[1]);

		for (j = leftCount; j < n; ++j){
			len = word[j].length();
			if (i < len){

				//BUG9
				if (myCount[0][CurrentLetter] > 0){
					if (myCount[1][CurrentLetter] >= myCount[0][CurrentLetter]){
						MP[Pos(i, j)] = CurrentLetter;
					}
					else{
						MP[Pos(i, j)] = -1;
					}
					++myCount[1][CurrentLetter];
				}//如果左右有重复的字母

				else{
					MP[Pos(i, j)] = CurrentLetter;
				}

			}//if  长度够

			else{
				MP[Pos(i, j)] = -1;
			}
		}
		




	}//for  外层循环  0 --- m-1
}

void fillAndUpdateAns(){
	int i, j, k;
	string ts = s;
	int visCopy[10];//BUG10
	int valCopy[26];//BUG10
	memcpy(visCopy, vis, sizeof(vis));
	memcpy(valCopy, val, sizeof(val));

	for (i = 0; i < 26; ++i){
		if (letterExist[i] && valCopy[i] == -1){
			for (j = 0; j < 10; ++j){
				if (!visCopy[j]){
					if (j == 0 && notZero[i]){ continue; }
					visCopy[j] = 1;
					valCopy[i] = j;
					break;//BUG11
				}//if visCopy[] == 0
			}
		}
	}//for 0 ... 26

	if (hasAns == 0){
		memcpy(finalVal, valCopy, sizeof(valCopy));
		hasAns = 1;
	}
	else{
		for (i = 0; i < 26; ++i){
			if (letterExist[i] && valCopy[i] < finalVal[i]){//BUG11
				memcpy(finalVal, valCopy, sizeof(valCopy));
				return;
			}
		}
	}
	return;

}

inline void init(){
	memset(val, -1, sizeof(val));
	memset(finalVal, -1, sizeof(finalVal));
	mem(vis);
	mem(notZero);
	mem(letterExist);
	kindCount = 0;
	word.clear();
	MP.clear();
	hasAns = 0;
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
	//if (DEBUG3){
	//	cout << letter << "\n\n";
	//}

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
				word.push_back(temps);
				k = i + 1;

			}//else

		}//for 遍历每一字符

		temps = reverse(s.substr(k, i - k));
		int lenTemps = temps.length();
		if (lenTemps > 1){
			notZero[temps[lenTemps - 1] - 'A'] = 1;
		}
		m = MAX(m, lenTemps);
		word.push_back(temps);
		++rightCount;//BUG1


		n = leftCount + rightCount;//计算word总个数

		if (kindCount <= 10){


			//----------------
			pickUseless();
			if (DEBUG4){
				printMap();
			}
			dfs(0, 0, 0);
			//----------------
			string ts = s;
			if (hasAns){
				for (i = 0; i < ts.length(); ++i){
					if (isupper(ts[i])){
						ts[i] = '0' + finalVal[ts[i] - 'A'];
					}
				}//for
				cout << ts << "\n";
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