/*姓名：王冰
  学号：13101020125
  班级：计13-1
*/

# include <stdio.h>
# define N 20
int eat ( int n )
{
	int n1, n2;
	//printf ( "%d\n", n );
	if ( n==1 )
	{
		return 1;
	}
	if ( n==2 )
	{
		return 2;
	}
	if ( n>2 )
	{
		n1 = eat(n-1);
		n2 = eat(n-2);
		return (n1+n2);
	}
}

int main ()
{
	int n, i;
	scanf ( "%d", &n );
	printf ( "%d\n", eat (n) );
	return 0;
	

}