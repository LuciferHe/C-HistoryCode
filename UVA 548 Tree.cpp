/*
You are to determine the value of the leaf node in a given binary tree that is the terminal node of a path of least value from the root of the binary tree to any leaf. The value of a path is the sum of values of nodes along that path.

Input 

The input file will contain a description of the binary tree given as the inorder and postorder traversal sequences of that tree. Your program will read two line (until end of file) from the input file. The first line will contain the sequence of values associated with an inorder traversal of the tree and the second line will contain the sequence of values associated with a postorder traversal of the tree. All values will be different, greater than zero and less than 10000. You may assume that no binary tree will have more than 10000 nodes or less than 1 node.
Output 

For each tree description you should output the value of the leaf node of a path of least value. In the case of multiple paths of least value you should pick the one with the least value on the terminal node.
Sample Input 

3 2 1 4 5 7 6
3 1 2 5 6 7 4
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
255
255
Sample Output 

1
3
255

*/



#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;
char s[100005];
int v1[100005], v2[100005], top;
int min_sum, ans;
int init(char *s, int *v)
{
	int top = 0;
	for (int i = 0; s[i]; i++)
	{
		while (s[i] == ' ')
			i++;
		v[top] = 0;
		while (s[i] && isdigit(s[i]))
		{
			v[top] = v[top] * 10 + s[i] - '0';
			i++;
		}
		top++;
		if (!s[i]) break;
	}
	return top;
}
int find(int *v, int n, int c)
{
	for (int i = n - 1; i >= 0; i--)
	if (v[i] == c)
		return i;
	return 0;
}
void build(int n, int *v1, int *v2, int sum)
{
	if (n <= 0)
		return;

	int p = find(v1, n, v2[n - 1]);

	sum += v2[n - 1];

	if (p <= 0 && n - p - 1 <= 0)
	{
		if (sum == min_sum)
			ans = ans < v2[n - 1] ? ans : v2[n - 1];
		else if (sum<min_sum)
		{
			min_sum = sum;
			ans = v2[n - 1];
		}
		return;
	}

	build(p, v1, v2, sum);
	build(n - p - 1, v1 + p + 1, v2 + p, sum);
}

int main()
{
	while (gets(s))
	{
		int v;
		init(s, v1);
		gets(s);
		top = init(s, v2);

		ans = min_sum = 10000000;
		build(top, v1, v2, 0);

		printf("%d\n", ans);
	}
	return 0;
}