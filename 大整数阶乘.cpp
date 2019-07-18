/*
姓名：王冰
学校：北方工业大学
班级：计13-1
学号：13101020125*/

#include<stdio.h>
#include<string.h>
#include<windows.h>
# define N 3000
int main()
{
	int n;
	int f[N];
	while (scanf("%d", &n) != EOF)
	{
		memset(f, 0, sizeof(f));
		f[0] = 1;
		int i;
		for (i = 2; i <= n; i++)
		{
			int c = 0;
			for (int j = 0; j<N; j++)
			{
				int s = f[j] * i + c;
				f[j] = s % 10;
				c = s / 10;
			}
		}
		int j = N - 1;
		while (f[j] == 0) j--;
		for (i = j; i >= 0; i--) printf("%d", f[i]);
		printf("\n");
	}
	return 0;
}