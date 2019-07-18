# include <stdio.h>
int judge ( int k, int n )
{
	int a[100], i=0, j;
	while ( n!=0 )
	{
		a[i] = n%k;
		n = n/k;
		i++;
	}
	for ( j=0; j<( (i+1)/2); j++ )
	{
		if ( a[j] !=a[i-1-j] ) break;
	}
	if ( j== ( (i+1)/2) ) return 1;
	else return 0;
}


int main ()
{
	int num, i, flag = 0;
	scanf ( "%d", &num );
	for ( i=2; i<17; i++ )
	{
		if ( judge ( i, num ) )
		{ printf ( "%d ", i ); flag =1;}
	}
	if ( flag==0 )  printf ("No!");
	printf ( "\n" );
	return 0;

}