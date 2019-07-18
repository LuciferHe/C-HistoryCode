#include<cstdio>

int gcd(int a,int b){
	return b == 0 ? a : gcd(b,a%b);
}

int main(){
	int a, b;
	scanf("%d%d",&a,&b);
	int ans = gcd(a,b);
	printf("\na与b的最大公约数为:%d\n\n",ans);
	return 0;
}