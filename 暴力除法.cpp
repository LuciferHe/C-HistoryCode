/*
姓名：王冰
学号：13101020125
班级：计13-1 */

# include<stdio.h>
# include<string.h>
# include<math.h>
# include<cstring>

const int N = 1000;

int dif ( int a[], int n )
{
	int c[10];
	for ( int i=0; i<n; i++ )
		c[i] = a[i];
	for ( i=0; i<n; i++ )
		for ( int j=0; j<n; j++ )
		if ( i!=j && c[i]==c[j] )	return 0;
	return 1;
}


int main ()
{
	int n;
	while ( scanf( "%d", &n )==1 )
	{
	int a[5];
	for ( a[0]=0; a[0]<10; a[0]++ )
	for ( a[1]=0; a[1]<10; a[1]++ )
	if ( dif(a,2) )
	{for ( a[2]=0; a[2]<10; a[2]++ )
		if ( dif(a,3)  )
		{for ( a[3]=0; a[3]<10; a[3]++ )
			if ( dif(a,4) )
			{for ( a[4]=0; a[4]<10; a[4]++ )
				if ( dif(a,5) ) 
				{
				int y = a[0]*10000+a[1]*1000+a[2]*100+a[3]*10+a[4]; 
				int x = y*n;
				if ( x>9999 && x<=98765 )
				{char str[6];
				sprintf ( str, "%d", x );
				int b[10];
				for ( int i=0; i<5; i++ )
					b[i] = str[i] - '0';
				for ( i=0; i<5; i++ )
					b[i+5] = a[i];
				if ( dif( b, 10 ) )  
					printf ( "%d/%d%d%d%d%d=%d\n",x, a[0], a[1], a[2], a[3], a[4], n  );
}
}			
}
}
}
}
}
