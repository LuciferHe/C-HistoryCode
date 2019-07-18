#include"stdafx.h"
#include "stdio.h"
#include"math.h"
void main()
{
	double y;
	int m, x;
	for (y = 1; y>0; y -= 0.1)
	{
		m = asin(y) * 10;
		for (x = 1; x<m; x++)
			printf(" ");
		printf("*");
		for (; x<31 - m; x++)
			printf(" ");
		printf("*\n");
	}
	for (y = 0; y >= -1; y -= 0.1)
	{
		m = asin(y) * 10;
		for (x = 1; x<(32 - m); x++)
			printf(" ");
		printf("*");
		for (; x<62 + m; x++)
			printf(" ");
		printf("*\n");
	}

}