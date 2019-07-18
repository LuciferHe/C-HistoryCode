/*
姓名：王冰
学号：13101020125
班级：计13-1 */


# include <stdio.h>
# include <math.h>


const int N = 1000;

int main()
{
	int n, a[N], temp;
	while ( scanf( "%d", &n )==1 )
	{
		for ( int i=0; i<n; i++ )
			scanf ( "%d", &a[i] );
		for ( i=0; i<n; i++ )
			for ( int j=i+1; j<n; j++ )
				if ( a[i]<a[j] )
				{ temp = a[i]; a[i] = a[j]; a[j] = temp; }
		int *p = a, *pend = a + n -1, sum = 1, flag = 0, temp = 2147483647+1;
		while ( p<=pend )
		{
			if ( *p )  { sum *= *p; flag = 1; }
			if ( *(p-1)>=0 && *p<0 )  temp = *p;
			p++;
		}
		if ( sum<0 )
		{
			if ( temp!=2147483647+1 )  printf ( "%d\n", sum/temp );
			else  printf ( "%d\n", sum/a[0] );
		}
		else
		{
			if ( !flag )	printf ( "0\n" );
			else            printf ( "%d\n",sum );
		}
	}
	return 0;
}



