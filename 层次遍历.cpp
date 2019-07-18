/*
姓名：王冰
学号：13101020125
班级：计13-1 */

# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include<cstring>
# include<cstdio>
# include<stack>


const int MAXN = 100000;
char s[MAXN+10];
int failed;


typedef	struct Tnode
{
	int have_value;
	int v;
	struct Tnode * left, * right;
}Node;

Node * root;

Node * newnode()
{
	Node * u;
	if ( (u = (Node*)malloc( sizeof(Node)))!=NULL )
	{
		u->have_value = 0;
		u->left = u->right = NULL;
	}
	return u;
}



void addnode( int v, char * s )
{
	int n = strlen( s );
	Node * u = root;
	for ( int i=0; i<n; i++ )
	{
		if ( s[i]=='L' )
		{
			if ( u->left==NULL )	u->left = newnode();
			u = u->left;
		}
		
		if ( s[i]=='R' )
		{
			if ( u->right==NULL )	u->right = newnode();
			u = u->right;
		}
	}
	if ( u->have_value )	failed = 1;

	u->v = v;
	u->have_value = 1;
}


int read_input()
{
	failed = 0;
	root = newnode();
	while (1)
	{
		if (scanf("%s",s)!=1)	return 0;
		if ( !strcmp(s,"()") )	break;
		int v;
		sscanf ( &s[1], "%d", &v );
		addnode ( v, strchr(s,',')+1 );
	}
	return 1;
}


int n=0, ans[MAXN]={0};
int bfs ()
{
	int front = 0, rear = 1;
	Node * q[MAXN];
	q[0] = root;
	while ( front<rear )    //有点绕
	{
		Node * u = q[ front++ ];
		if ( !u->have_value ) return 0;

		ans[ n++ ] = u->v;
		if ( u->left!=NULL ) q[rear++] = u->left;
		if ( u->right!=NULL ) q[rear++] = u->right;
	}
	for ( int i=0; i<n; i++ )	printf ( "%d ",ans[i] );
	printf ( "\n" );
	return 1;
}


int main()
{
	if ( read_input() ) 
	{
		int u = bfs();
		if ( !u || failed ) printf ( "-1\n" );
	}
	else
		printf ( "Input error!\n" );
	return 0;
}