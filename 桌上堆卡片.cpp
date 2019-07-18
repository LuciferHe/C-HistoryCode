/*1/2 + 1/3 + 1/4 +...+ 1/(n+1) <= c 对给定的c(0.01<= c <=5.20),求n的最大值*/

# include <stdio.h>
void fun( float n )
{
	int i;
	float sum=0.00;
	for ( i=1; sum<=n; i++ )
		sum += (1.0/(i+1) );
	printf ( "%d\n", i-1 );
}
int main()
{
	float a[20];
	int i=0, j;
	while ( 1 )
	{
		scanf ( "%f", &a[i] );
		if ( a[i]==0.00 ) break;

		i++;
	}
	for ( j=0; j<i; j++ )
	{	fun ( a[j] );}
	return 0;
}