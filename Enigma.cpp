# include<stdio.h>
# include<string.h>

int main()
{
	int i, j;
	int n, t;
	int iChange[3][26];
	int iConvert[3];
	char cTemp[1000];
	int iCase = 0;
	int m;
	while ( scanf ("%d",&m) && m )
	{
		if (iCase++) printf("\n");
		printf( "Enigma %d:\n", iCase );
		for ( i=0; i<3; i++ )
		{
			scanf ( "%s", cTemp );
			for ( j=0; j<m; j++ )
			{
				iChange[i][cTemp[j]-'A'] = j - ( cTemp[j]-'A');
			}
		}
		scanf ( "%d", &n );
		while (n--)
		{
			scanf ( "%s", cTemp );
			for ( i=0; i<strlen(cTemp); i++ )//?aид??и╣и║???идик?a
			{
				iConvert[0] = i%m;
				iConvert[1] = (i/m)%m;
				iConvert[2] = (i/(m*m))%m;
				 t = cTemp[i] - 'A';
				for ( j=2; j>=0; j-- )
				{
					t += iChange[j][(t-iConvert[j]+m)%m];
					t = (t+m)%m;
				}
				printf ( "%c", t+'a' );
			}
			printf ( "\n" );
		}
	}
	return 0;
}