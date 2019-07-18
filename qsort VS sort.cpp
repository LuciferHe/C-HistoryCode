# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include <algorithm>

using namespace std;

const int N = 100;

int cmp ( const void * a, const void * b )
{
	return ( *(int*)b - *(int*)a );
}


static unsigned int next = 1; 

int rand1(){
	next = next * 1103515245 + 12345;
	return ( unsigned int ) ( next/65536)%32768;
}

void srand1 ( unsigned int seed ){
	next = seed;
}


int main()
{
	int a[N]={0};
	int i;
	for ( i=0; i<N; i++ )
	{
		srand1 ( (unsigned)i );
		if ( i==2 || i==3 || i==4 || i==5 ) a[N-1-i] = 425;
		else        a[N-1-i] = rand1();
	}

	sort ( a, a+N );
	//qsort ( a, N, sizeof(a[0]), cmp);
	for ( i=0; i<N; i++ )
		printf ( "%d ", a[i] );
	printf ( "\n" );
	return 0;
}

