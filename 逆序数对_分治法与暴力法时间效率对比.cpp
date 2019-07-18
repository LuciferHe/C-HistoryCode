#include <iostream>
#include<windows.h>
using namespace std;
#define DEBUG 0
LARGE_INTEGER BegainTime;  //开始时间
LARGE_INTEGER EndTime;    //结束时间
LARGE_INTEGER Frequency;  //频率

long long int fun(int* a, int l, int r){//[l,r)
	int n = r - l;
	if (n <= 1){
		return 0;
	}
	else{
		int* T = new int[n];
		int m = l + n / 2;
		long long int L = fun(a, l, m);
		long long int R = fun(a, m, r);
		long long int M = 0;
		int p = l;
		int q = m;
		for (int i = 0; i != n; ++i){
			if (q != r && (p >= m || a[p] > a[q])){
				T[i] = a[q++];
				M += (m-p);
			}
			else{
				T[i] = a[p++];
			}
		}
		if (DEBUG){ cout << ".....\n"; }
		for (int i = l; i != r; ++i){
			a[i] = T[i-l];
		}
		delete[] T;
		return L + R + M;
	}
}

long long int fun2(int* a, int n){//[0....n-1]
	long long int C = 0;
	for (int i = 0; i != n; ++i){
		for (int j = i + 1; j != n; ++j){
			if (a[i] > a[j])++C;
		}
	}
	return C;
}

int main(){
	int n = 0;
	while (cin >> n){//n为非负数
		int* a = new int[n];
		for (int i = 0; i != n; ++i){
			cin >> a[i];
		}
		QueryPerformanceFrequency(&Frequency);
		QueryPerformanceCounter(&BegainTime);
		//cout << "The result is " << fun(a, 0, n) << endl;
		cout << "The result is " << fun2(a, n) << endl;
		QueryPerformanceCounter(&EndTime);
		cout<<"运行时间（ms）: "<< (double)(EndTime.QuadPart - BegainTime.QuadPart)<<endl;
		delete[] a;
	}
	return 0;
}