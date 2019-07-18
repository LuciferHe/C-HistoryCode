/*
姓名：王冰
学号：13101020125
班级：计13-1

*/

#include <stdio.h>
#include <string.h>
# define N 100
int main()
{
	int i, j, i1, j1,
		a[N][N], b[N][N];
	printf ( "请输入行数：" );
	scanf ( "%d", &i1 );
	printf ( "\n请输入列数：" );
	scanf ( "%d", &j1 );
	printf ( "\n请输入其中的元素：\n" );
	for ( i=1; i<i1+1; i++ )
	{
		for ( j=1; j<j1+1; j++ )
		{
			scanf ( "%d", &a[i][j] );
		}
	}

	for ( j=1; j<i1+1; j++ )
	{
		for ( i=1; i<j1+1; i++ )
		{
			b[i][j] = a[j][i];
		}
	}

	printf ( "\n转置行列式为：\n" );


	for ( i=1; i<j1+1; i++ )
	{
		for ( j=1; j<i1+1; j++ )
		{
			printf ( "%d ", b[i][j] );
		}
		printf ( "\n" );
	}

	return 0;

}