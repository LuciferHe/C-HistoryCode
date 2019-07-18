# include<stdio.h>
# include<string.h>
char s[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";//Õæ¿Óµù
int main ()
{
	int i, c;
	while ( (c=getchar()) != '\0' )
	{
		for ( i=0;  i<strlen(s); i++ )
		{
			if ( s[i]==c ) 
			{
				printf ( "%c", s[i-1] );
				break;
			}
		}
		if ( i==strlen(s) )  printf ( "%c", c );
	}
	return 0;
}



