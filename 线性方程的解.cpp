/*
姓名：王冰
学号：13101020125
班级：计13-1 */


# include<stdio.h>
//# include<string.h>

double x, y;

void solve( double a, double b, double c, double d, double e, double f )
{
	double D = a*e - b*d;
	double D1 = c*e - b*f;
	double D2 = a*f - c*d;
	x = D1/D; y = D2/D;
}

int main()
{
	double a, b, c, d, e, f;
	scanf ( "%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f );
	solve ( a, b, c, d, e, f );
	printf ( "%.2f  %.2f\n", x, y );
	return 0;
}
