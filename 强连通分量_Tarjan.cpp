#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define N 10005				// 题目中可能的最大点数 
stack<int>sta;				// 存储已遍历的结点 
vector<int>gra[N];			// 邻接表表示图 
int dfn[N];					// 深度优先搜索访问次序 
int low[N];					// 能追溯到的最早的次序 
int InStack[N];				// 检查是否在栈中(2为在栈中，1为已访问，且不在栈中，0为不在) 
vector<int> Component[N]; 	// 获得强连通分量结果
int InComponent[N];			// 记录每个点在第几号强连通分量里
int index, ComponentNumber;	// 索引号，强连通分量个数 
int n, m;					// 点数，边数 

void init(void)
{
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(InStack, 0, sizeof(InStack));
	index = ComponentNumber = 0;
	for (int i = 1; i <= n; ++i)
	{
		gra[i].clear();
		Component[i].clear();
	}

	while (!sta.empty())
		sta.pop();
}

void tarjan(int u)
{
	InStack[u] = 2;
	low[u] = dfn[u] = ++index;
	sta.push(u);

	for (int i = 0; i < gra[u].size(); ++i)
	{
		int t = gra[u][i];
		if (dfn[t] == 0)
		{
			tarjan(t);
			low[u] = MIN(low[u], low[t]);
		}
		else if (InStack[t] == 2)
		{
			low[u] = MIN(low[u], dfn[t]);
		}
	}

	if (low[u] == dfn[u])
	{
		++ComponentNumber;
		while (!sta.empty())
		{
			int j = sta.top();
			sta.pop();
			InStack[j] = 1;
			Component[ComponentNumber].push_back(j);
			InComponent[j] = ComponentNumber;
			if (j == u) break;
		}
	}
}

void input(void)
{
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		gra[a].push_back(b);
	}
}

void solve(void)
{
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	if (ComponentNumber>1)
		puts("No");
	else
		puts("Yes");
}

int main()
{
	while (scanf("%d%d", &n, &m), n + m)
	{
		init();
		input();
		solve();
	}
}
