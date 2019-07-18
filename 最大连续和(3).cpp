#include <iostream>
using namespace std;

int maxsum(int* A, int x, int y){//[x,y)中的最大连续和
	int i, m, v, L, R, max;
	if ((y - x) == 1)return A[x];
	m = x + (y-x) / 2;
	//max = maxsum(A,x,m)>?maxsum(A,m,y);  >?运算符？？？？？
	int a = maxsum(A, x, m); int b = maxsum(A, m, y);
	max = a > b ? a : b;
	v = 0; L = A[m-1];
	for (i = m - 1; i >= x; --i){v += A[i];L = L > v ? L : v;}
	v = 0; R = A[m];
	for (i = m; i < y; ++i){ v += A[i]; R = R > v ? R : v; }
	return max > (L + R) ? max : (L + R);
}


int main(){
	while (1){
		int n = 0;
		cout << "Please input n:";
		cin >> n; if (!n) break;
		int A[100] = { 0 };
		for (int i = 0; i < n; ++i){
			cin >> A[i + 1];
		}
		cout << "max_sum is " << maxsum(A,1,n+1) << endl;
	}
	return 0;
}
