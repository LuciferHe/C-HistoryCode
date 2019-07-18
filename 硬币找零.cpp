#include <cstdio>
#include <cstring>
#define N 7500
const int m[10] = { 0, 50, 25, 10, 5, 1 };
int dp[N][10];

void dfs(int n, int p)//剩余n元钱，用m[p...5]这几种硬币，有多少种不同组合
{
	if (dp[n][p] != -1)
		return;
	dp[n][p] = 0;
	for (int i = p; i <= 5; i++)
	{
		if (n - m[i] >= 0)
		{
			dfs(n - m[i], i);
			dp[n][p] += dp[n - m[i]][i];
		}
	}
	return;
}
int main()
{
	int n;
	memset(dp, -1, sizeof(dp));
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= 5; i++)
			dp[0][i] = 1;
		dfs(n, 1);
		printf("%d\n", dp[n][1]);
	}
	return 0;
}