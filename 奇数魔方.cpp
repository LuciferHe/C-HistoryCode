/*魔方阵，古代又称“纵横图”，是指组成元素为自然数1、2…n2的平方的n×n的方阵，其中每个元素值都不相等，且每行、每列以及主、副对角线上各n个元素之和都相等。
下面这个程序就告诉你奇数阶魔方阵的奥秘。弄清内部机理，从此你可以徒手写出任意奇数阶魔方阵了。*/
# include <stdio.h>
# include <string.h>
# define N 300
int main()
{
	int n = 0;

	printf("	输入您想要魔方的阶数(奇数)：");
	while (scanf("%d", &n) == 1 && n){
		int i = 0, j = 0; //i 表示 行， j 表示 列
		int	k = 0;
		int a[N][N] = { 0 };
		j = n / 2 + 1;
		a[1][j] = 1;//给第一行中间的空位  赋值
		for (k = 2; k <= n*n; k++)
		{
			i--; //往上走一步
			j++; //往右走一步
			if (i<1 && j>n)//如果跑到右上角去了
			{
				i += 2;  //往下走两步
				j--;     //往左走一步
			}
			else
			{
				if (i<1)  //跑到上边界去了
					i = n;//跳到最后一行
				if (j>n)  //跑到右边界去了
					j = 1;//跳到第一列
			}
			if (a[i][j] == 0) //如果没有赋值
				a[i][j] = k;
			else //如果已经赋值了，就换个位置
			{
				i += 2; //往下两步
				j--;    //往左一步
				a[i][j] = k;  
			}
		}//for


		printf("\n	您想要的魔方阵如下：\n\n");
		for (i = 1; i <= n; i++)
		{
			printf("	");
			for (j = 1; j <= n; j++)
			{
				printf("%-4d ", a[i][j]);
			}
			printf("\n");
		}
		printf("\n	");
	}
	return 0;
}