/*
从前面16个坐标中，分别找到与下面点距离最近的点，并输出
0 0 0
255 255 255
0 0 1
1 1 1
128 0 0
0 128 0
128 128 0
0 0 128
126 168 9
35 86 34
133 41 193
128 0 128
0 128 128
128 128 128
255 0 0
0 1 0

0 0 0
255 255 255 
253 254 255
77 79 134
81 218 0
-1 0 0*/


# include<stdio.h>
struct color
{
	int r, g, b;
}map[16];

int main()
{
	int i, index, min;
	int d;
	struct color temp; 
	for ( i=0; i<16; i++ )
	{
		scanf ( "%d%d%d", &map[i].r, &map[i].g, &map[i].b );
	}

	while ( scanf ( "%d%d%d", &temp.r, &temp.g, &temp.b ) && temp.r>-1 )
	{
		min = 99999;
		for ( i=0; i<16; i++ )
		{
			d = ( temp.r-map[i].r )	* ( temp.r-map[i].r )	+
				( temp.g-map[i].g )	* ( temp.g-map[i].g )	+
				( temp.b-map[i].b )	* ( temp.b-map[i].b );	
				if ( min > d )
				{
					min = d;
					index = i;
				}
		}
		printf ( "(%d,%d,%d) maps to (", temp.r,temp.g, temp.b );
		printf ( "%d,%d,%d)", map[index].r, map[index].g, map[index].b );
	}
	return 0;
}