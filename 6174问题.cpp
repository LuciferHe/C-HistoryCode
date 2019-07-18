/*假设你有一个各位数字互不相同的四位数，把所有数字从大到小排序得到a, 从小到大排序得到b，然后用a-b替换原来这个数, 并且继续操作。例如，从1234出发，依次可以得到4321-1234=3087、8730-378=8352、8532-2358=6174.有趣的是，7641-1467=6174，回到了他自己。
输入一个各位数字互不相同的四位数，输出操作序列，你会有神奇的发现。*/
#include<stdio.h>
# define N 5

int fun(int a)
{
	int i = 0;
	char s1[N] = { '\0' };
	sprintf(s1, "%d", a);  //把整数a变成字符串s1；sprintf函数 包含于stdio.h中
	for (i = 0; i < 4; i++){
		for (int j = i + 1; j<4; j++)
		{
			if (s1[i]<s1[j])  //从大到小排序
			{
				char temp1 = s1[i]; s1[i] = s1[j]; s1[j] = temp1;
			}
		}
	}
	int max = 0;
	sscanf(s1, "%d", &max);  //把字符串s1变成整数max；sscanf函数 包含于stdio.h中
	char s2[N] = { '\0' };
	for (i = 0; i<4; i++)
		s2[i] = s1[4-1-i];//将s1反过来，存入s2
	int min = 0;
	sscanf(s2, "%d", &min);  //把字符串s2变成整数min；
	int temp = max - min;
	printf("%d\n", temp);
	if (a == temp) return 0;
	else         fun(temp);//递归调用
}

int main()
{
	int s = 0;
	while (scanf("%d", &s) == 1 && s)	fun(s);
	return 0;
}




