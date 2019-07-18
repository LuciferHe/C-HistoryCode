
#include <stdio.h>

int main()
{
	int number;

	printf("请输入0-5之间的数字：\n");
	for (;;)
	{
		//fflush(stdin);  加上这句话 输入字符就不会陷入死循环了
		scanf("%d", &number);
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