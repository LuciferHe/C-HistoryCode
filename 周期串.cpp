/*
姓名：王冰
学校：北方工业大学
班级：计13-1
学号：13101020125*/
# include <stdio.h>
# include <string.h>
int main ()
{
	char str[1000];
	scanf ( "%s", str );
	int len = strlen(str);
	for ( int i=1; i<=len; i++ )
	{
	    int flag = 1;
		if ( len%i==0 )
		{
			for ( int j=0; j<len; j++ )
			{
				if ( str[j] != str[j%i] )
				{ flag = 0; break;}
			}
			if ( flag ) {printf ( "%d\n", i ); break;}
		}
	}
	return 0;
}