/*
姓名:王冰
学校:北方工业大学
班级:计13-1
学号:13101020125*/



# include<stdio.h>
# include<windows.h>
int main ()
{
	char str[6] = {"123"};
	printf( "%s\n",str );
	memset (str,0,sizeof(str));
	printf( "%s\n",str );
	return 0;
}



