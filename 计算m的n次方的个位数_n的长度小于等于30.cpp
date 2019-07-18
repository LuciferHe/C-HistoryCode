//-----------------------------------------------------
//All Rights Reserved, Copyright (C) 2015, beyourself
//-----------------------------------------------------

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MEM(a) memset(a, 0, sizeof(a))
const int MAXN = 30 + 5;

int dig[MAXN];
int len;
int A;
int _A;
int ans;

inline void init(){
	MEM(dig);
	len = 0;
	A = 0;
	ans = 1;
}

void reduceOne(){
	int i;
	for (i = 0; i < len - 1; ++i){
		if (dig[i] == 0 || dig[i] == -1){
			--dig[i + 1];
			dig[i] = 9;
			if (dig[i + 1] == 0) break;
		}
		else{
			--dig[i];
			break;
		}
	}
	if (dig[len - 1] == 0) { --len; }
}


void half(){
	int first = 1, reduce = 0;
	int i, j;
	if (dig[len - 1] == 1){ reduce = 1; }
	for (i = len - 1; i >= 0;){
		if (dig[i] == 0){
			--i; continue;
		}
		if (dig[i] % 2){
			int t = dig[i];
			for (j = i - 1; j >= 0; --j){
				t = t * 10 + dig[j];
				if (t % 2 == 0){
					t /= 2;
					int lenDig = i - j;
					while (lenDig >= 0){
						dig[i - lenDig] = t % 10;
						t /= 10;
						--lenDig;
					}
					i = j - 1;
					break;
				}
			}//for 往后遍历
		}//if dig[i] 奇数
		else{
			dig[i] /= 2;
			--i;
		}
	}// for i  遍历
	if (reduce) --len;
}

void f(){
	if (len == 1){

		for (int i = 0; i < dig[0]; ++i){
			ans = (ans * A) % 10;
		}

		return;
	}

	while (len > 1){
		if (dig[0] % 2){//奇数
			ans = (ans*A) % 10;
			reduceOne();

		}
		else{//偶数
			A = (A*A) % 10;
			half();

		}
	}//while
	f();
}


int _f(int n){
	int t = 1;
	for (int i = 0; i < n; ++i){
		t = (t*_A) % 10;//BUG2
	}
	return t;
}

int main(){
	int i;
	int cas;
	string m, n;
	cin >> cas;
	while (cas--){
		init();
		cin >> m >> n;

		A = m[m.length() - 1] - '0';
		_A = A;
		if (A == 0){ cout << "0\n"; }
		else if (A == 1){ cout << "1\n"; }
		else if (A == 5){ cout << "5\n"; }
		else if (A == 6){ cout << "6\n"; }
		else {
			len = n.length();
			for (i = 0; i < len; ++i){ dig[len - 1 - i] = n[i] - '0'; }//BUG1
			f();
			
			//更简单的方法
			int __ans, __n;
			if (len >= 2){
				string str = n.substr(len - 2, 2);
				__n = atoi(str.c_str());
			}
			else{
				__n = atoi(n.c_str());
			}
			__ans = _f(__n);
			if (__ans == ans){ cout << "\n\nRight\n\n"; }
			else{ cout << "\n\nWrong!\n\n"; }
			
		}
	}//while
	return 0;
}