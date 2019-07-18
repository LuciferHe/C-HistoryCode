/*已知三角形三个顶点A、B、C的坐标，和另外一个点D的坐标，判断点D是否在三角形ABC内。
这是一道简单的数学题，如何用程序来实现呢？
*/
# include<stdio.h>

double x[4];
double y[4];

double area(double x0, double y0, double x1, double y1, double x2, double y2)
{
	return x0*y1 + x2*y0 + x1*y2 - x2*y1 - x0*y2 - x1*y0;
	//三角形有向面积的2倍
}

int main()
{
	while (1)
	{
		for (int i = 1; i <= 3; i++)
		{
			printf("请输入三角形第%d个顶点的坐标，中间以空格分开：", i);
			scanf("%lf%lf", &x[i], &y[i]);
		}
		printf("\n输入要判断的点的坐标，中间以空格分开：");
		scanf("%lf%lf", &x[0], &y[0]);
		if ((area(x[1], y[1], x[2], y[2], x[3], y[3])
			- area(x[0], y[0], x[1], y[1], x[2], y[2])
			- area(x[0], y[0], x[2], y[2], x[3], y[3])
			- area(x[0], y[0], x[3], y[3], x[1], y[1]))
			<= 1e-9)     //判断大三角形的面积是否等于三个小三角形面积之和
			 printf("\n该点在三角形内。\n");
		else printf("\n该点不在三角形内。\n");

		printf("\n输入0退出，输入1继续:  ");
		int temp; scanf("%d", &temp);
		printf("\n");
		if (!temp) break;
	}
}

