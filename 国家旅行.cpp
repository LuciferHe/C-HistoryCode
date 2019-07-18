# include<stdio.h>
int main()
{
	int i, j, 
		num, b[13]={1};
	float a[6][6], money;
	for ( i=1; i<=5; i++ )
	{
		for ( j=1; j<=5; j++ )
		{
			scanf ( "%f", &a[i][j] );
		}
	}
	while (1)
	{
		scanf ( "%d", &num );
		b[num+1]=1.00;
		if (num!=0)
		{
			for ( i=1; i<=num; i++ )
			{
				scanf ( "%d", &b[i] );
			}
			scanf ( "%f", &money );
			for ( j=1; j<=num+1; j++ )
			{
				money = money*a[b[j-1]][b[j]];
				money = (int)( money*100 + 0.5 );
				money /= 100;
			}
			
			printf ( "%.2f\n", money );
		}
		else break;
	}


}

/*
1 1.57556 1.10521 0.691426 7.25005
0.634602 1 0.701196 0.43856 4.59847
0.904750 1.42647 1 0.625627 6.55957
1.44616 2.28059 1.59840 1 10.4843
0.137931 0.217555 0.152449 0.0953772 1
3 2 4 5 20.00
1 3 100.00
6 2 3 4 2 4 3 120.03
0



19.98
99.99
120.01
*/