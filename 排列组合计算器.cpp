#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define uint64 unsigned long long
const uint64 INF = 18446744073709551615;
const int MAXN = 10000;
void A();
void C();
void A(int m, int n);
uint64 C(uint64 m, uint64 n);
int Bit(uint64 num);


void A(){
	int m, n;
	printf("\nm n: ");
	scanf("%d%d",&m,&n);
	A(m,n);
}

void C(){
	uint64 m, n, ans;
	printf("\nm n: ");
	scanf("%llu%llu", &m, &n);
	ans = C(m, n);
	printf("\nC(%llu,%llu) = %llu(%d位)\n\n", m, n, ans,Bit(ans));
}

void A(int m, int n){
	int i,j;
	int f[MAXN], c=0, s=0;
	memset(f,0,sizeof(f));
	f[0] = 1;
	for (i = (m - n + 1); i <= m; ++i){
		c = 0;
		for (j=0;j<MAXN;++j){
			s = f[j] * i + c;
			f[j] = s % 10;
			c = s / 10;
		}
	}
	printf("A(%d,%d) = ",m,n);
	j = MAXN - 1;
	while (f[j] == 0) --j;
	for (i = j; i >= 0; --i) printf("%d",f[i]);
	printf(" (%d位)\n",j+1);
}


uint64 C(uint64 m, uint64 n){
	uint64 up = 1;
	uint64 down = 1;
	uint64 ans = 1;
	uint64 t = 0;
	if (n > m){ printf("Error! n>m !\n"); exit(0); }
	if (n == 0 || n == m) return 1;
	uint64 i = 1;
	for (i = 1; i <= n; ++i){
		down *= i;
		if ((i + (m - n)) > (INF / (ans*up))){ printf("\n\nOverFlow!!\n\n"); return 0; }
		up *= (i + (m - n));
		t = ans * up;
		if ((t - down*(t / down)) == 0){ ans = t / down; up = 1; down = 1; }
	}
	return (ans*up) / down;
}

int Bit(uint64 num){
	uint64 t = num;
	int i = 0;
	while (t){
		t /= 10; ++i;
	}
	return i;
}


int main(){
	int choice, count=0;
	printf("\n\n欢迎来到排列组合计算器!\n\nPowered by Wang Bing!\n\n\n");
	while (1){
		if (count % 10 == 0){ system("CLS"); }
		++count;
		printf("A(m,n) -- 1\n");
		printf("C(m,n) -- 2\n");
		printf("Exit   -- 0\n");
		printf("\nChoice: ");
		scanf("%d",&choice);
		switch (choice)
		{
		case 0: exit(1);
		case 1: A(); break;
		case 2: C(); break;
		default: printf("\nWrong input!\n\n"); break;
		}
	}
	return 0;
}