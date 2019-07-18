//输入正整数 n 和 m, 输出 n%m (n<=10^100   m<=10^9)
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 100;

int main(){
	char n[MAXN];
	int m = 0;
	while (~scanf("%s%d",n,&m)){
		int len = strlen(n);
		int ans = 0;
		for (int i = 0; i < len; ++i){
			ans = (int)(((long long)ans*10 + (n[i]-'0'))%m);
		}
		printf("ans:%d\n\n",ans);
	}
	return 0;
}