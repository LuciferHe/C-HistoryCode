
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int number;

	printf("请输入0-5之间的数字：\n");
	for (;;)
	{
		
		//cin.clear(); //清空cin错误标识
		//cin.sync(); //刷新缓冲区
		cin >> number;
		if (number >= 0 && number <= 5)
		{
			printf("你输入的数字是%d。\n", number);
			break;
		}
		else
		{
			printf("输入有误，请重新输入！\n");
		}
	}
	return 0;
}