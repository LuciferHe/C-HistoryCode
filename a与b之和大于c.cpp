/*
姓名：王冰
学号：13101020125
班级：计13-1 */

//亮点：没有进位直接比较，这就是数组的优势。。
# include<stdio.h>
# include<string.h>

int d[1000]={0};
void fun ( char a[] )
{
    int A = strlen (a);
    int aa[1000]={0};
    int i;
    for ( i=0; i<A; i++ )
        aa[i] = a[A-1-i] - '0';
    for ( i=0; i<1000; i++ )
        d[i] += aa[i];
}

int main ()
{
   char a[1000]={'\0'}, b[1000]={'\0'}, c[1000]={'\0'};
   scanf ( "%s", a ); 
   scanf ( "%s", b ); 
   scanf ( "%s", c );
   fun ( a );
   fun ( b );
   char temp[1000] = {'\0'};
   int i = 1000-1;
   while ( d[i]==0 ) i--;
   for ( int j=0; j<=i; j++ )
    temp[j] = d[i-j] + '0';

   int A = strlen(temp);
   int B = strlen(c);
   if ( A>B ) printf ( "YES\n" );
   if ( A<B ) printf ( "NO\n" );
   if ( A==B )
   {
        int temp1 = strcmp ( temp,c );
        if ( temp1>0 ) printf ( "YES\n" );
        if ( temp1<0 ) printf ( "NO\n" );
        if ( temp1==0 ) printf ( "Equal\n" );
   }
   return 0;
}
