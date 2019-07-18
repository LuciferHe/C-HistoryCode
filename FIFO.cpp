/*
姓名：王冰
学号：13101020125
班级：计13-1 */

# include<stdio.h>
# include<stdlib.h>


# include<cstdio>
# include<queue>

using namespace std;

queue<int>q;

int main()
{
	int n;
	scanf ( "%d", &n );
	for ( int i=0; i<n; i++ )	q.push( i+1 );
	while ( !q.empty () )
	{
		printf ( "%d ", q.front () );
		q.pop();
		q.push( q.front () );
		q.pop();
	}
	return 0;
}