# include <stdio.h>

int aTure, bTure;

int judge( int m, int n, int p )
{
	if (aTure) return 0;
	if ( m==1 && n==1 )
	{
		aTure = 1;
		return 0;
	}
	if ( n==1 ) bTure = 1;
	while( p>1 )
	{
		if ( m%p==0 ) judge( m/p, n, p-1 );
		if ( n%p==0 ) judge( m, n/p, p-1 );
		p--;
	}
	return 0;
}

int main ()
{
	int a, b, temp;
	while ( scanf ("%d%d", &a,&b) && a>0 )
	{
		if ( a<b )
		{
			temp = a;
			a = b;
			b = temp;
		}
		aTure = 0;
		bTure = 0;
		judge ( a, b, 100 );
		if (!aTure&&bTure) printf ( "%d\n", b );
		else printf ( "%d\n", a );
	}
	return 0;
}