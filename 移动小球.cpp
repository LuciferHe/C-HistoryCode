/*
姓名：王冰
学号：13101020125
班级：计13-1 */

# include<stdio.h>
# include<stdlib.h>


typedef struct node * pNode;


struct node
{
	pNode left, right;
	int num;
};

pNode create( int n )
{
	pNode head, now, newnode;
	
	if ( ( head=(pNode)malloc(sizeof(node)))==NULL )
	{
		printf ( "Can't find the space for head!\n" );
		exit (0);
	}
	
	head->left = NULL;
	head->right = NULL;
	head->num = 0;

	now = head;
	
	for ( int i=0; i<n; i++ )
	{
		if ( ( newnode=(pNode)malloc(sizeof(node)))==NULL )
		{
			printf ( "Can't find the space for newnode!\n" );
			exit (0);
		}
		
		newnode->num = i+1;
		newnode->left = now;
		now->right = newnode;
		now = newnode;
	}

	now->right = head;
	head->left = now;
	return (head);
}


pNode search ( pNode head, int num )
{
	pNode now;
	int temp;

	now = head->right;

	while ( now!=head )
	{
		if ( (temp=now->num)==num )	return (now);
		else now = now->right;
	}
	printf ( "Can't find the data!\n" );
	return NULL;
}

void A ( pNode x, pNode y )
{
	(x->right)->left = x->left;
	(x->left)->right = x->right;
	(x->right) = y;
	(x->left) = y->left;
	(y->left)->right = x;
	y->left = x;
}

void B ( pNode x, pNode y )
{
	(x->right)->left = x->left;
	(x->left)->right = x->right;
	(x->left) = y;
	(x->right) = y->right;
	(y->right)->left = x;
	y->right = x;
}

void print ( pNode head )
{
	pNode temp;
	temp = head->right;
	while ( temp!=head->left )
	{
		printf ( "%d ", temp->num );
		temp = temp->right;
	}
	printf ( "%d\n", head->left->num );
}


int main()
{
	int n, m;
	char str[3];
	scanf ( "%d%d", &n, &m );
	pNode head = create ( n );
	for ( int i=0; i<m; i++ )
	{s
		scanf ( "%s", str );
		int a, b;
		scanf ( "%d%d", &a, &b );
		pNode x, y;
		x = search ( head, a );
		y = search ( head, b );
		if ( str[0]=='A' )	A( x, y );
		if ( str[0]=='B' )	B( x, y );
	}
	print ( head );
	return 0;
}






