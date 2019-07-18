//http://blog.csdn.net/frankiller/article/details/7755749
//http://ufownl.blog.163.com/blog/static/1250122200810114174831/
/*
题目解释：

機器手臂有以下幾種合法搬積木的方式（a和b是積木的編號）：
move a onto b
 在將a搬到b上之前，先將a和b上的積木放回原來的位置（例如：1就放回1的最開始位罝）
move a over b
 在將a搬到b所在的那堆積木之上之前，先將a上的積木放回原來的位罝（b所在的那堆積木不動）
pile a onto b
 將a本身和其上的積木一起放到b上，在搬之前b上方的積木放回原位
pile a over b
 將a本身和其上的積木一起搬到到b所在的那堆積木之上
quit
 動作結束
前四個動作中若a=b，或者a, b在同一堆積木中，那麼這樣的動作算是不合法的。所有不合法的動作應該被忽略，也就是對各積木均無改變.


测试数据：
Sample Input 
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit

Sample Output 
 0: 0
 1: 1 9 2 4
 2:
 3: 3
 4:
 5: 5 8 7 6
 6:
 7:
 8:
 9:





Sample Input 
21
move 2 onto 1
move 3 onto 2
move 4 onto 3
move 5 over 1
pile 1 over 10
move 9 over 8
move 11 over 8
pile 3 over 8
pile 8 over 3
move 20 over 19
pile 19 over 18
pile 18 onto 15
move 15 over 3
pile 20 onto 19
pile 19 onto 18
pile 18 over 17
quit

Sample Output
0: 0
1:
2:
3:
4:
5:
6: 6
7: 7
8: 8 9 11 3 4 5 15
9:
10: 10 1 2
11:
12: 12
13: 13
14: 14
15:
16: 16
17: 17 18 19 20
18:
19:
20:
*/




#include"stdafx.h"
#include <stdio.h>
#include <string.h>
struct node
{
	int num, block[30];
}a[30];
int postion[30];
void turnback(int x)
{
	int i, j, pos, t = postion[x], T, s = 0;
	for (i = 1; i <= a[t].num; i++)
	if (a[t].block[i] == x) { pos = i; break; }
	for (i = pos + 1; i <= a[t].num; i++)
	{
		T = a[t].block[i];
		++a[T].num; ++s;
		for (j = a[T].num; j >= 2; j--)
			a[T].block[j] = a[T].block[j - 1];
		a[T].block[1] = T;
		postion[T] = T;
	}
	a[t].num = a[t].num - s;
};
void move1(int x, int y)
{
	int i, pos, t = postion[x], T = postion[y];
	++a[T].num;
	a[T].block[a[T].num] = x;
	for (i = 1; i <= a[t].num; i++)
	if (a[t].block[i] == x) { pos = i; break; }
	for (i = pos; i<a[t].num; i++)
		a[t].block[i] = a[t].block[i + 1];
	--a[t].num;
	postion[x] = postion[y];
}
void move2(int x, int y)
{
	int i, pos, t = postion[x], T = postion[y], s = 0;
	for (i = 1; i <= a[t].num; i++)
	if (a[t].block[i] == x) { pos = i; break; }
	for (i = pos; i <= a[t].num; i++)
	{
		++a[T].num; ++s;
		a[T].block[a[T].num] = a[t].block[i];
		postion[a[t].block[i]] = T;
	}
	a[t].num = a[t].num - s;
};
int main()
{
	char s[30], s1[30];
	int i, j, n, x, y;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i<n; i++)
		{
			a[i].num = 1;
			a[i].block[1] = i;
			postion[i] = i;
		}
		while (scanf("%s", &s))
		{
			if (strcmp(s, "quit") == 0) break;
			scanf("%d%s%d", &x, &s1, &y);
			if ((postion[x] != postion[y]) && (x != y))
			{
				if ((strcmp(s, "move") == 0) && (strcmp(s1, "onto") == 0))
				{
					turnback(x); turnback(y); move1(x, y);
				}
				if ((strcmp(s, "move") == 0) && (strcmp(s1, "over") == 0))
				{
					turnback(x); move1(x, y);
				}
				if ((strcmp(s, "pile") == 0) && (strcmp(s1, "onto") == 0))
				{
					turnback(y); move2(x, y);
				}
				if ((strcmp(s, "pile") == 0) && (strcmp(s1, "over") == 0))
				{
					move2(x, y);
				}
			}
		}
		for (i = 0; i<n; i++)
		{
			printf("%d:", i);
			for (j = 1; j <= a[i].num; j++)
				printf(" %d", a[i].block[j]);
			printf("\n");
		}
	}
	return 0;
}
