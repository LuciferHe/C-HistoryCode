# include<stdio.h>
# include<string.h>
# include<windows.h>

int main ()
{
	int a, b;
	char str[100], *p, *p_end, temp;
	while ( gets(str) )
	{
		a = 0; b =0;
		p = str;
		p_end = p + strlen(str) - 1;
		for (; p<=p_end; p++)
		{ 
			while( 1 )
			{
				while ( *p>='0' && *p<='9' )
				{
					a = a*10 + (*p-'0');
					p++;
				}
				if ( *p=='+' || *p=='-' || *p=='*' || *p=='/') break;
				p++;

			}
				temp = *p;
				while (1)
				{
					while ( *p>='0' && *p<='9' )
					{
						b = b*10 + (*p-'0');
						p++;
					}
					if (  p == p_end + 1 ) break;
					p++;
					
				}
				switch (temp)
				{
					case '+': printf ( "%d\n", a+b );break;
					case '-': printf ( "%d\n", a-b );break;
					case '*': printf ( "%d\n", a*b );break;
					case '/': printf ( "%d\n", a/(b+0.00) );break;
					default : printf ( "Error\n" );break;
				}
			
		}
		memset( str, 0, strlen(str) );
	}
	return 0;
}



