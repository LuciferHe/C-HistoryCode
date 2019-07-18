/*
姓名:王冰
学校:北方工业大学
班级:计13-1
学号:13101020125*/



# include<stdio.h>
int main ()
{
	char c, flag = 1;
	while ( (c=getchar()) != EOF )
	{
		if ( c=='"' ) { printf ( "%s", flag?"“":"”" ); flag = !flag;}

			else printf ("%c", c );
	}
	return 0;
}



