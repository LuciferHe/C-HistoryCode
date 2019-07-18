/*
姓名：王冰
学号：13101020125
班级：计13-1 */

# include<stdio.h>
# include<cstring>

const int N = 1000;

int mat[N][N], vis[N][N];

void dfs ( int x, int y )
{
	if ( !mat[x][y] || vis[x][y] )	return;
	vis[x][y] = 1;
	dfs (x-1,y+1);dfs (x,y+1);dfs (x+1,y+1);
	dfs (x-1,y);			  dfs (x+1,y);
	dfs (x-1,y-1);dfs (x,y-1);dfs (x+1,y-1);
}

int main()
{
	int n;
	while ( scanf("%d",&n)==1 )
	{
		memset( mat, 0, sizeof(mat) );
		memset( vis, 0, sizeof(vis) );
		char s[N];
		for ( int i=0; i<n; i++ )
		{
			scanf( "%s", s );
			for ( int j=0; j<n; j++ )
				mat[i+1][j+1] = s[j]-'0';
		}
		int count = 0;
		for ( i=1; i<=n; i++ )
			for ( int j=1; j<=n; j++ )
				if ( mat[i][j] && !vis[i][j] )
				{
					count++; 
					dfs(i,j); 
				}
		printf ( "\nThe result is:%d\n", count );
	}
	return 0;
}