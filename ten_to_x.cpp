# include<stdio.h>

 ten_to_x ( int num, int x )
 {
	 int temp;
	 temp = num%x;
	 num /= x;
	 if (num>0) ten_to_x ( num, x );
	 printf ( "%d", temp );
 }

 int main ()
 {
	 int num;
	 scanf ( "%d", &num );
	 ten_to_x ( num, 2 );
 }