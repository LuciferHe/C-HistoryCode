/*
姓名：王冰
学号：13101020125
班级：计13-1 */

# include<stdio.h>
# include<stdlib.h>


# include<cstdio>
# include<stack>

int main()
{
	int n, m;
	while ( scanf( "%d%d", &n, &m )==2 )
	{
		int k=1;
		for ( int i=0; i<n-1; i++ )
			if ( m%2 ) { k=2*k; m=(m+1)/2; }
			else { k=2*k+1; m=m/2; }
		printf ( "%d\n", k );
	}
	return 0;
}