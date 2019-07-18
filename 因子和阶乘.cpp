/*
姓名：王冰
学号：13101020125
班级：计13-1 */


# include<stdio.h>
# include<assert.h>
# include<windows.h>
//# include<string.h>

int prime[100], count=0;
	
int is_prime( int a )
{
	assert ( a>=0 );
	if ( a==1 ) return 0;
	for ( int i=2; i*i<=a; i++ )
		{ if( a%i==0 ) return 0;}
	return 1;
}

int main()
{	
	for ( int i=2; i<100; i++ )
	{
		if ( is_prime(i) ) prime[count++] = i;
	}	
	int p[100], maxp, n;
	while ( scanf( "%d", &n ) == 1 )
	{
		maxp = 0;
		memset( p, 0, sizeof(p));
		printf ( "%d!=", n );
		for ( int i=2; i<=n; i++ )
		{
			int m = i;
			for ( int j=0; j<count; j++ )
			{
				while( m%prime[j]==0 )
				{
					m /= prime[j];
					p[j]++;
					if ( j>maxp ) maxp = j;
				}
			}
		}
		for ( i=0; i<=maxp; i++ )
			printf ( "%d ", p[i] );
		printf ( "\n" );
	}
	return 0;
}



