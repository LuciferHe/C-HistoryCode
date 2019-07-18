/*

代码来源：http://www.cnblogs.com/g0feng/archive/2012/10/27/2742948.html
大意：给出n种国家的货币汇率，一定金额的某种货币经过一系列汇率变换后再换成原来货币，金额增加了，求出这样的一个变换，要求变换步数最少。

 

Floyd变形，关于Floyd动态规划的理解。

 

状态转移方程：
f[k][i][j]=min(f[k-1][i][j],f[k-1][i][k]+f[k-1][k][j])
f[k][i][j]表示只经过前k个点(包括k)，从i到j的最小值。当k从1到n时，就是从i到j的最小值。我们熟悉的用二维数组的写法实际上是对空间的一种压缩。
解释一下：
计算只经过前k个点，从i到j的最小值时，有两种情况需要考虑：经过第k个点和不经过第k个点。经过第k个点则距离应是从i到k的最小值和从k到j的最小值，两个最小值的路径都必须只经过前k-1个点（为什么是k-1而不是k，事实上他们两数值相同，因为起点和终点已经有第k个点，只是在dp的过程中先产生k-1，f[k][i][k]和f[k][k][j]有可能比f[k][i][j]的值晚计算出，就不能在计算f[k][i][j]时用到这两个值）。不经过k的点则距离与只经过前k-1个点时一样。
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

#define MAXN 110
#define INF 0x3f3f3f3f

double d[MAXN][MAXN][MAXN];
int path[MAXN][MAXN][MAXN];

int n, m;

void print_path(int s, int e, int step)
{
	if (step == 0)
	{
		printf("%d", s);
	}
	else
	{
		print_path(s, path[s][e][step], step - 1);
		printf(" %d", e);
	}
}

void Floyd()
{
	for (int step = 2; step <= n; step++) //步数 
	{
		for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		if (d[i][j][step] < d[i][k][step - 1] * d[k][j][1])
		{
			d[i][j][step] = d[i][k][step - 1] * d[k][j][1];
			path[i][j][step] = k;
		}
		for (int i = 1; i <= n; i++)
		{
			if (d[i][i][step] > 1.01)
			{
				print_path(i, i, step);
				printf("\n");
				return;
			}
		}
	}
	printf("no arbitrage sequence exists\n");
}

void init()
{
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) d[i][i][1] = 1.0;
		}
	}
}

int main()
{
	while (~scanf("%d", &n))
	{
		init();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) if (i != j)
			{
				scanf("%lf", &d[i][j][1]);
				path[i][j][1] = j;
			}
		}
		Floyd();
	}
	return 0;
}