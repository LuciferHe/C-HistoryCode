/*
姓名：王冰
学号：13101020125
班级：计13-1 */

//问题描述：你有一块椭圆的地，你可以在边界上选n个点，两两连接得到n*(n-1)/2条线段，它们最多能把土地分成多少部分？
# include<stdio.h>

int main ()
{
	int n;
	scanf ( "%d", &n );
	int sum1=0, sum2=0;
	for ( int i=0; i<=n-2; i++ )
	{ sum1 += i*(n-2-i); sum2 += (i*(n-2-i)+1); } 
	int v = n + (n/4.0)*sum1;
	int e = n + (n/2.0)*sum2;
	printf ( "%d\n", e-v+1 );
	return 0;
}