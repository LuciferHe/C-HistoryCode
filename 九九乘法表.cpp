/*
姓名：王冰
学号：13101020125
班级：计13-1
*/

# include <stdio.h> 
int main ()
{
	int i, j;
	for ( i=1; i<10; i++ )
	{
		for ( j=1; j<10; j++ )
		{
			printf ( "%d*%d=%d ", j, i, i*j );
		}
		printf ( "\n" );
	}

		
	return 0;
}


