#include<cstdio>
#include<cmath>
using namespace std;

const int MAXN = 10000;
int euler_phi(int n){//未给出正整数n(n>1)的唯一分解式: n = p1^a1 * p2^a2 * ... * pk^ak，求1-n中与n互质的数的个数
	//依照公式 phi(n) = n*((p1-1)/p1)*((p2-1)/p2)*...*((pk-1)/pk)
	if (n < 2)return 0;
	int m = sqrt(n+0.5);
	int ans = n;
	for (int i = 2; i <= m; ++i)if(n%i == 0){
		ans = ans / i * (i-1);
		while (n%i == 0) n /= i;
	}
	if (n > 1)ans = ans / n * (n-1);
	return ans;
}

void phi_table(int n, int* arr){
	//可预先置所有数的欧拉函数值都为它本身.
	//由定理可知，如果p是一个正整数且满足φ（p）=p-1,那么p是素数.
	//在遍历过程中如果遇到欧拉函数与自身相等的情况,那么说明该数为素数:
	//把这个数的欧拉函数值改变，同时也把能被素因子整除的数改变。
	if (n < 2)return;
	int i, j;
	for (i = 1; i <= n; i++) //预置
		arr[i] = i;
	for (i = 2; i <= n; i += 2)//把2和2的倍数的欧拉函数值改变 n*((2-1)/2) = n/2
		arr[i] /= 2;
	for (i = 3; i <= n; i += 2) if (arr[i] == i) {//如果这个数是素数
		for (j = i; j <= n; j += i)//把它本身和它的倍数的欧拉值改变
			arr[j] = arr[j] / i * (i - 1);
	}
}

int main(){
	int n;
	int phi[MAXN];
	
	scanf("%d", &n);
	phi_table(n, phi);
	for (int i = 2; i <= n; ++i){
		printf("%d的欧拉值:%d  ",i,phi[i]);
		if (i % 5 == 0)printf("\n\n");
	}
	return 0;
}