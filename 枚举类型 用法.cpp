#include<stdio.h>



/* 定义枚举类型 */

enum DAY { MON = 1, TUE, WED, THU, FRI, SAT, SUN };



void main()

{

	/* 使用基本数据类型声明变量，然后对变量赋值 */

	int x, y, z;



	x = 10;

	y = 20;

	z = 30;



	/* 使用枚举类型声明变量，再对枚举型变量赋值 */

	enum DAY yesterday, today, tomorrow;



	yesterday = MON;

	today = TUE;

	tomorrow = WED;



	printf("%d %d %d \n", yesterday, today, tomorrow);

}