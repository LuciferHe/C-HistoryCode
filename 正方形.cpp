/*
姓名：王冰
学号：13101020125
班级：计13-1
*/

# include <stdio.h> 
int main ()
{
	int i, j,
		n;
	scanf ( "%d", &n );
	for ( i=0; i<n; i++ )
	{
		if ( i==0 || i==n-1 )
		{
			for ( j=0; j<n; j++ )
			{
				printf ( "* " );
			}
			printf ( "\n" );
		}
		else
		{
			for ( j=0; j<2*n; j++ )
			{
				if( j==0 || j==(2*n-2) )
					printf ( "*" );
				else 
					printf ( " " );
			}
			printf ( "\n" );
		}

	}
	return 0;
}


