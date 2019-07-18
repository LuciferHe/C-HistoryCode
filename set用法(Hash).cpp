题目：http://acm.hust.edu.cn/vjudge/problem/viewProblem.action?id=19516 
题解：http://www.cnblogs.com/g0feng/archive/2012/10/11/2720540.html


#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

struct node
{
	int x, y, step;
	char map[5][5];
	bool operator < (node t) const{
		return (memcmp(map,t.map,25)) < 0;
	}
}p, q;

int dx[] = { -1, 1, -2, 2, -1, 1, -2, 2 };
int dy[] = { -2, -2, -1, -1, 2, 2, 1, 1 };

char goal[5][5] = { '1', '1', '1', '1', '1',
'0', '1', '1', '1', '1',
'0', '0', ' ', '1', '1',
'0', '0', '0', '0', '1',
'0', '0', '0', '0', '0' };


queue<node> Q;
set<node> vis;
int bx, by;

int check(int r, int c)
{
	if (r >= 0 && r < 5 && c >= 0 && c < 5) return 1;
	return 0;
}

void init()
{
	while (!Q.empty()) Q.pop();
	vis.clear();
}

int try_to_insert(node s)
{
	if (vis.count(s)) return 0;
	vis.insert(s);
	return 1;
} //hash

void bfs(node &p)
{
	init();
	if (memcmp(p.map, goal, sizeof(goal)) == 0)
	{
		printf("Solvable in 0 move(s).\n");
		return;
	}
	Q.push(p);
	while (!Q.empty())
	{
		p = Q.front();    Q.pop();
		if (p.step >= 11)
		{
			printf("Unsolvable in less than 11 move(s).\n");
			return;
		}
		if (memcmp(p.map, goal, sizeof(goal)) == 0)
		{
			printf("Solvable in %d move(s).\n", p.step);
			return;
		}
		for (int i = 0; i < 8; i++)
		{
			q = p;
			q.x += dx[i];
			q.y += dy[i];
			q.step++;
			if (!check(q.x, q.y)) continue;
			char tmp = q.map[p.x][p.y];
			q.map[p.x][p.y] = q.map[q.x][q.y];
			q.map[q.x][q.y] = tmp;     //模拟状态转移过程 
			if (try_to_insert(q))
			{
				Q.push(q);
			}
		}
	}
	return;
}

int main()
{
	int T;
	scanf("%d", &T);
	getchar();
	while (T--)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				scanf("%c", &p.map[i][j]);
				if (p.map[i][j] == ' ')
				{
					bx = i;
					by = j;
				}
			}
			getchar();
		}
		p.x = bx, p.y = by, p.step = 0;
		bfs(p);
	}
	return 0;
}