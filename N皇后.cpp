# include<stdio.h>
//# include<string.h>

const int N = 100;

int tot = 0, c[N] = {0}, vis[3][N] = {0};

void search ( int row, int n ){
	int i, j, k;
	if ( row==n ){
		tot++;
		for ( k=0; k<n; k++ )
			printf ( "%d",c[k] );
		printf ( "\n" );
	}
	else
		for ( i=0; i<n; i++ ){
			if ( !vis[0][i] && !vis[1][row+i] && !vis[2][row-i+n] ){
				c[row] = i;
				vis[0][i] = vis[1][row+i] = vis[2][row-i+n] = 1;
				search ( row+1, n );
				vis[0][i] = vis[1][row+i] = vis[2][row-i+n] = 0;
			}
		}
}

int main(){
	int n;
	scanf ( "%d", &n );
	search ( 0, n );
	printf ( "%d\n", tot );
	return 0;
}