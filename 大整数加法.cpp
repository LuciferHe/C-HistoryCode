/*
姓名：王冰
学校：北方工业大学
班级：计13-1
学号：13101020125*/

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
	int D = (A>B?A:B);
	int C = D +2;
	for ( int i=1; i<=A; i++ ) aa[i] = a[A-i] - '0';
	for ( i=1; i<=B; i++ ) ab[i] = b[B-i] - '0';
	for ( i=1; i<=D; i++ )
		s[i] += aa[i] + ab[i]; 
	for ( i=1; i<=C; i++)
		{ s[i+1] += s[i]/10; s[i] %= 10; }
	while ( s[C]==0 ) C--;
	for ( i=C; i>=1; i-- )
		printf ( "%d", s[i] );
	printf ( "\n" );
	return 0;
}