# include <stdio.h>
float fun( int m, int n )
{
	if ( m%2==0 || n%2==0 ) return (m*n+0.00);
	else					return (m*n+.41);
}
int main()
{
	int i, n, a[20][2];
	scanf ( "%d", &n );
	for ( i=0; i<n; i++ )
		scanf ( "%d%d", &a[i][0], &a[i][1] );
	for ( i=0; i<n; i++ )
		printf ( "%.2f\n", fun( a[i][0], a[i][1]) );
	return 0;
}