/*
姓名：王冰
学校：北方工业大学
班级：计13-1
学号：13101020125*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int root ( int n )
{
	int a = ( sqrt(1+8*n) - 1 ) /2;
	return a;
}

int main ()
{
	int n;
	while ( scanf ( "%d", &n ) != EOF )
	{
		int temp = root ( n );
		int deno = n - ( (temp*(temp+1))/2);
		int nume = ( temp + 2 - deno );
		if ( deno==0 )
		{
			if ( temp%2==0 ) printf ( "%d/1\n", temp );
			else
				printf ( "1/%d\n", temp );
		}
		else
		{	
			if ( temp%2!=0 ) printf ( "%d/%d\n", deno, nume );
			else
				printf ( "%d/%d\n", nume, deno );
		}
	}
	return 0;
}

正常的规则：

int main ()
{
	int n;
	while ( scanf ("%d", &n) == 1 )
	{
		int k = (int)floor ( (sqrt(8.0*n+1)-1)/2-1e-9) + 1;
		int s = k*(k+1)/2;
		printf ( "%d/%d\n", s-n+1, k-s+n );
	}
	return 0;
}