# include<stdio.h>
# include<string.h>
# include<assert.h>

const int N = 100;

int rand0(){
	static unsigned int next = 1;
	next = next * 1103515245 + 12345;
	return ( unsigned int ) ( next/65536)%32768;
}


int main (){
	int count;
	for ( count=0; count<5; count++ )
		printf ( "%hd\n", rand0() );
	return 0;
}