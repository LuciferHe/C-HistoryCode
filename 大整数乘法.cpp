/*【问题描述】求两个不超过200位的非负整数的积。
【输入形式】有两行，每行是一个不超过200位的非负整数，没有多余的前导。
【输出形式】一行，即相乘后的结果。结果不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
【样例输入】12345678900 98765432100
【样例输出】1219326311126352690000*/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100]={'\0'}, b[100]={'\0'};
	int aa[100]={0}, ab[100]={0}, s[100]={0};
	scanf ( "%s", a );
	scanf ( "%s", b );
	int A = strlen(a);
	int B = strlen(b);
	int C = A + B +1;
	for ( int i=1; i<=A; i++ ) aa[i] = a[A-i] - '0';
	for ( i=1; i<=B; i++ ) ab[i] = b[B-i] - '0';
	for ( i=1; i<=A; i++ )
		for ( int j=1; j<=B; j++ )  s[i+j-1] += aa[i]*ab[j];
	for ( i=1; i<=C; i++)
		{ s[i+1] += s[i]/10; s[i] %= 10; }
	while ( s[C]==0 ) C--;
	for ( i=C; i>=1; i-- )
		printf ( "%d", s[i] );
	printf ( "\n" );
	return 0;
}