/*图形打印是练习C语言基本功的一种方式，那么小伙伴们想知道下面这段程序会打印出什么呢？Just try it.
不知道你们看出来没有，这里面蕴含了递归那不为人知的另外一种用法。*/
# include<stdio.h>

void stars(int num, int i)
{
	int  j,temp;
	for (j = 0; j<num - i; j++)
		printf(" ");
	for (j = 0; j<2 * i - 1; j++)
		printf("*");
	printf("\n");
	temp = i + 1;
	if (i<num) stars(num, temp);
	if (i != num)
	{
		for (j = 0; j<num - i; j++)
			printf(" ");
		for (j = 0; j<2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
}

void main()
{
	int num;
	while (scanf("%d", &num) == 1 && num)
	stars(num, 1);
}