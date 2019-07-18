/*
姓名：王冰
学号：13101020125
班级：计13-1 */

# include<stdio.h>
# include<math.h>
# include<cstring>

const int N = 1000;

struct mins
{
	int No, number;
}min[N];

int judge ( int a, int n, int k )
{
	for ( int i=1; i<=n; i++ )	
		if ( a<min[i].number || k==1 )	return 0;
	return 1;
}

int main()
{
	int count, n, temp;
	while ( scanf ( "%d", &n )==1 )
	{
		count = 1;
		for ( int i=1; i<=n; i++ )
		{
			scanf ( "%d", &temp );	
			if ( i==1 )   { min[1].No = 1; min[1].number = temp; }
			if ( judge( temp, count, i ) )  { min[++count].number = temp; }
			else
			{
				min[0].No = 0;
				min[0].number = 999999999;
				for ( int j=1; j<=count; j++ )
				if ( temp<min[j].number )	
				{
					 if ( min[0].number>min[j].number )
					{ min[0].No = j; min[0].number=min[j].number; }
				}
				min[min[0].No].number = temp;
			}
		}
		printf ( "%d\n", count );
		memset( min, 0, sizeof(min));
	}
	return 0;
}