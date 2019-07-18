#include<cstdio>
using namespace std;

/* 低效的算法
int pow_mod(int a, int n, int m){
	int ans = a;
	for (int i = 0; i < n; ++i){
		ans = (int)((long long)ans * a %m);
	}
	return ans;
} */

//高效的分治法
int pow_mod(int a, int n, int m){
	if (n == 1){ return a%m; }
	int x = pow_mod(a,n/2,m);
	long long ans = (long long)x * x % m;
	if (n % 2 == 1) ans = ans * a % m;
	return (int)ans;
}
int main(){
	int a, n, m;
	while (~scanf("%d%d%d",&a, &n, &m)){//输出(a^n)%m a,n,m<=int
		printf("ans:%d \n", pow_mod(a, n, m));
	}
	return 0;
}