#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>

#include<map>

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
const int MAXN = 0;
const double EPS = 1e-9;
const double OO = 1e15;
//const double PI = acos(-1.0); //M_PI; cmath



string getHint(string secret, string guess) {
	map<int, int> m1;
	map<int, int> m2;
	stringstream ss;
	string ans;
	int a = 0, b = 0, i;
	for (i = 0; i < secret.length(); ++i){
		if (secret[i] == guess[i]) ++a;
		else{
			if (m1.count(secret[i])) ++m1[secret[i]];
			else m1[secret[i]] = 1;

			if (m2.count(guess[i])) ++m2[guess[i]];
			else m2[guess[i]] = 1;
		}
	}

	for (i = '0'; i <= '9'; ++i){
		if (m1.count(i) && m2.count(i)) b += (m1[i]<m2[i]?m1[i]:m2[i]);
	}

	ss << a << "A" << b << "B";
	ss >> ans;
	cout << ans;
	return ans;
}


inline void init(){

}
int dblcmp(double d){// -1:d<0; 1:d>0; 0:d=0 用来比较两个浮点数大小
	return d < -EPS ? -1 : d > EPS;
}

int main(){
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int i, j;
	string a, b;
	cin >> a;
	cin >> b;
	getHint(a,b);
	return 0;
}



