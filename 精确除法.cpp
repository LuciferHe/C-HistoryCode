/*输入a,b,c输出a/b的小数形式，精确到小数点后c位。*/
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;
int a, b, c;

void fun(int n){
	if (n == c + 1){ printf("\n\n\n"); return; }
	if (a == 0){ printf("0"); fun(n + 1); return; }
	if (10 * a < b){ printf("0"); a *= 10; fun(n + 1); return; }
	a *= 10;
	int t = a / b;
	printf("%d", t); a %= b; fun(n + 1); return;
}

int main(){
	while (scanf("%d%d%d", &a, &b, &c) != EOF)
	{
		int t = a / b;
		printf("%d.", t);
		a %= b;
		fun(1);
	}
	return 0;
}