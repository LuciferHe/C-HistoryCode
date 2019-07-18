#include "stdafx.h"
#include <stdio.h>

int main(){
	int i = 0;
	int temp = 0;
	for (i = 0; i < 4; i++){
		printf( "This is the %dth circle.\n", i );
	}
	scanf( "%d", &temp );
	printf( "%d\n", temp );
	return 0;
}