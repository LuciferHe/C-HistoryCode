/*姓名：王冰
  学号：13101020125
  班级：计13-1
*/


# include <stdio.h>
# define N 100

void week ( int n )
{
	n = n%7;
	switch (n)
	{
	case 0: printf ( "Saturday\n" ); break;
	case 1: printf ( "Sunday\n" ); break;
	case 2: printf ( "Monday\n" ); break;
	case 3: printf ( "tuesday\n" ); break;
	case 4: printf ( "Wednesday\n" ); break;
	case 5: printf ( "Thursday\n" ); break;
	case 6: printf ( "Friday\n" ); break;
	}
}

int judge ( int y )
{
	if ( y%4==0 && y%100!=0 || y%400==0 ) 
		return 1;
	else
		return 0;
}


void date ( int n )
{
	int y, m, d, Feb;
	for ( y=2000, d=0; d<=n; y++ )
	{
		if ( judge(y) )
			d += 366;
		else
			d += 365;
	}
	y--;
	if ( judge(y) )
		d -= 366;
	else
		d -= 365;
	m=1;
	if ( judge(y) )
		Feb = 29;
	else
		Feb = 28;
	while ( d<=n )
	{
		switch (m)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:   m++;d+=31;break;
			case 2:    m++;d+=Feb;break;
			default :  m++;d+=30;break;
		}

	}
	m--;
	switch (m)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:   m++;d-=31;break;
			case 2:    m++;d-=Feb;break;
			default :  m++;d-=30;break;
		}
	d = n-d+1;
	printf ( "%d-%d-%d ", y, m, d );

	

}
void main() 
{
	int i, j, n[N];
	for ( i=0; n[i-1]!=-1; i++ )
	{
		scanf ( "%d", &n[i] );
	}
	for ( j=0; j<i-1; j++ )
	{
		date ( n[j] );
		week ( n[j] );
	}
	
}