//http://blog.csdn.net/pure_life/article/details/2910874
//#include"stdafx.h"
#include <iostream>
using namespace std;

const int MAXN = 110;



int      n = 4;
bool     flag[MAXN]; //访问标志数组
int      belg[MAXN]; //存储强连通分量,其中belg[i]表示顶点i属于第belg[i]个强连通分量
int      numb[MAXN]; //结束时间标记,其中numb[i]表示离开时间为i的顶点
int adj[MAXN][MAXN] = { {0}, { 2, 2, 3 }, { 0 }, { 1, 4 }, { 1, 1 } },
radj[MAXN][MAXN] = { { 0 }, { 1, 4 }, { 1, 1 }, { 1, 1 }, { 1, 3 } }; //邻接表,逆邻接表

//取图于数据结构157页  图7.1（a） G1





//用于第一次深搜,求得numb[1..n]的值
void VisitOne(int cur, int &sig)
{
	flag[cur] = true;

	for (int i = 1; i <= adj[cur][0]; ++i)
	{
		if (false == flag[adj[cur][i]])
		{
			VisitOne(adj[cur][i], sig);
		}
	}

	numb[++sig] = cur;
	printf( "%d  ", numb[sig] );
}

//用于第二次深搜,求得belg[1..n]的值
void VisitTwo(int cur, int sig)
{
	flag[cur] = true;
	belg[cur] = sig;

	printf( "%d属于第%d个强连通分量\n", cur, sig );

	for (int i = 1; i <= radj[cur][0]; ++i)
	{
		if (false == flag[radj[cur][i]])
		{
			VisitTwo(radj[cur][i], sig);
		}
	}
}

//Kosaraju算法,返回为强连通分量个数
//int Kosaraju_StronglyConnectedComponent()
int main()
{
	int  i, sig;

	//第一次深搜
	memset(flag + 1, 0, sizeof(bool)*n);
	for (sig = 0, i = 1; i <= n; ++i)
	{
		if (false == flag[i])
		{
			VisitOne(i, sig);
		}
	}

	printf( "\n" );

	//第二次深搜
	memset(flag + 1, 0, sizeof(bool)*n);
	for (sig = 0, i = n; i>0; --i)
	{
		if (false == flag[numb[i]])
		{
			VisitTwo(numb[i], ++sig);
		}
	}

	return sig;
}