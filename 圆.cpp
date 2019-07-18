#include<stdio.h>
#include<math.h>

void main(){
	double y; 
	int x, m;
	for (y = 10; y >= -10; --y){//圆的半径为10
		m = 2.5 * sqrt(100-y*y);
		//计算行对应的列坐标m。2.52.5是屏幕纵横比调节系数，否则显示出来的是椭圆
		for (x = 1; x < 30 - m; ++x) printf(" ");//图形左侧空白区域控制
		printf("*");//圆的左侧
		for (; x < 30 + m; ++x) printf(" ");//图形的空心部分控制
		printf("*\n");//圆的右侧
	}
}

