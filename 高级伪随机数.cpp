# include<stdio.h>
# include<string.h>
# include<assert.h>

const int N = 100;

static unsigned int next = 1; 

int rand1(){
	next = next * 1103515245 + 12345;
	return ( unsigned int ) ( next/65536)%32768;
}

void srand1 ( unsigned int seed ){
	next = seed;
}

int main (){
	int count;
	unsigned seed;
	printf ( "Please enter your choice for seed.\n" );
	while ( scanf("%u",&seed)==1 ){
		srand1( seed );
		for ( count=0; count<5; count++ )
			printf ( "%hd\n", rand1() );
		printf ( "Please enter next seed (q to quit):\n" );
	}
	return 0;
}