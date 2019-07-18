#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

const int MAXN = 1000000;
int n;
int prime[MAXN];
int vis[MAXN];
int main(){
	scanf("%d", &n);//1-n中有多少个素数
	int c = 0;
	memset(vis, 0, sizeof(vis));
	memset(prime, 0, sizeof(prime));
	for (int i = 2; i <= n; ++i)if (!vis[i]){//Eratosthenes筛法
		prime[c++] = i;
		printf("%d\n",i);
		for (int j = i*i; j <= n; j += i) vis[j] = 1;
	}//for
	return 0;
}