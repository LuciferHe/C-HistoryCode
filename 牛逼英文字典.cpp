/*
姓名：王冰
学校：北方工业大学
班级：计13-1
学号：13101020125*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int n;
char word[2000][7], sorted[2000][7];

int cmp_char ( const void *_a, const void *_b)
{
	char* a = ( char*)_a;
	char* b = ( char*)_b;
	return *a-*b;
}

int cmp_string ( const void *_a, const void *_b)
{
	char* a = ( char*)_a;
	char* b = ( char*)_b;
	return strcmp( a, b );
}

int main ()
{
	n = 0;
	while (1)
	{
		scanf ( "%s", word[n] );
		if ( word[n][0] == '*') break;
		n++;
	}
	qsort ( word, n, sizeof(word[0]), cmp_string );
	for ( int i=0; i<n; i++ )
	{
		strcpy ( sorted[i], word[i] );
		qsort ( sorted[i], strlen(sorted[i]), sizeof(char), cmp_char );
	}
	char s[7];
	while ( scanf ("%s", s) == 1 )
	{	
		qsort ( s, strlen(s), sizeof(char), cmp_char );
		int found = 0;
		for ( int i=0; i<n; i++ )
			if ( strcmp(sorted[i], s) == 0 )
			{ found = 1; printf ( "%s ", word[i] );}
		if ( !found ) printf ( ":(" );
		printf ( "\n" );
	}

	return 0;
}

