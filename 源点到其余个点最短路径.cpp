/*

见数据结构188页  图7.34
6
8
0
1
2
3
4
5
0
2
10
0
4
30
0
5
100
1
2
5
2
3
50
3
5
10
4
3
20
4
5
60
0*/

#include"stdafx.h"
#include<windows.h>
#include<windef.h>
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
const int MAXN = 100;
const int infinity = 2147483647;   //关于INFINITY有点。。。
class ArcCell{
public:
	int A;
	int B;
	int num;
	ArcCell(){
		A = '\0';
		B = '\0';
		num = 0;
	}
};
class MGraph{
public:
	int vexs[MAXN];
	int AdjMatrix[MAXN][MAXN];
	int vexnum, arcnum;
	MGraph(){
		memset(vexs, 0, sizeof(vexs));
		memset(AdjMatrix, 1, sizeof(AdjMatrix));
		vexnum = 0;
		arcnum = 0;
	}
};

typedef BOOL p[MAXN][MAXN];
typedef int d[MAXN];

//-------函数声明--------
int CreateDN(MGraph &G);
int LocateVex(MGraph G, char V);
void OutputAdjMatrix(MGraph G);
void ShortestPath_DIJ(MGraph G, int v0, p &P, d &D);
//-------函数声明--END---

void OutputAdjMatrix(MGraph G){
	int i = 0, j = 0;
	for (i = -1; i < G.vexnum; i++){
		if (i == -1) printf("%12s", " ");
		else{
			printf("%12d", G.vexs[i]);
		}
	}//for
	printf("\n");
	for (i = 0; i < G.vexnum; i++){
		printf("%12d", G.vexs[i]);
		for (j = 0; j < G.vexnum; j++){
			printf("%12d", G.AdjMatrix[i][j]);
		}//for
		printf("\n");
	}//for
}
int LocateVex(MGraph G, int V){
	int i = 0;
	for (i = 0; i < G.vexnum; i++){
		if (G.vexs[i] == V)
			return i;
	}
	return -1;
}
int CreateDN(MGraph &G) {//  算法 7.2
	// 采用数组（邻接矩阵）表示法，构造无向网G。
	int i=0, j, k, w;
	int  v1, v2;
	cout << "G.vexnum :"; cin >> G.vexnum;
	cout << "G.arcnum :"; cin >> G.arcnum;

	for (i = 0; i<G.vexnum; i++) {
		cout << "G.vex[" << i << "]:";
		cin >> G.vexs[i];
	} // 构造顶点向量

	for (k = 0; k<G.arcnum; ++k) {  // 构造邻接矩阵
		cout << "v1 (int) : ";  cin >> v1;
		cout << "v2 (int) : ";  cin >> v2;
		cout << "w (int) : ";   cin >> w;

		i = LocateVex(G, v1);  j = LocateVex(G, v2);// 确定v1和v2在G中位置

		G.AdjMatrix[i][j] = w;                // 弧<v1,v2>的权值
	}//for
	return 1;
} // CreateDN
void ShortestPath_DIJ(MGraph G, int v0, p &P, d &D)
{ // 算法7.15
	// 用Dijkstra算法求有向网G的v0顶点到其余顶点v的最短路径P[v]
	// 及其带权长度D[v]。
	// 若P[v][w]为TRUE，则w是从v0到v当前求得最短路径上的顶点。
	// final[v]为TRUE当且仅当v∈S,即已经求得从v0到v的最短路径。
	int i = 0, j, v, w, min;
	bool final[MAXN];
	for (v = 0; v<G.vexnum; ++v) {
		final[v] = FALSE;
		D[v] = G.AdjMatrix[v0][v];  //默认为矩阵上的权值
		for (w = 0; w<G.vexnum; ++w)  P[v][w] = FALSE;  // 设空路径
		if (D[v] < infinity) { P[v][v0] = TRUE;  P[v][v] = TRUE; } //若路径存在，??????
	}
	D[v0] = 0;  final[v0] = TRUE;        // 初始化，v0顶点属于S集
	//--- 开始主循环，每次求得v0到某个v顶点的最短路径，并加v到S集 ---

	//以上全是初始化
	for (i = 1; i<G.vexnum; ++i) {         // 其余G.vexnum-1个顶点
		min = infinity;                    // 当前所知离v0顶点的最近距离
		for (w = 0; w<G.vexnum; ++w)
		if (!final[w])                           // w顶点在V-S中
		if (D[w]<min) { v = w;  min = D[w]; }  // w顶点离v0顶点更近

		final[v] = TRUE;                       // 离v0顶点最近的v加入S集
		for (w = 0; w<G.vexnum; ++w)             // 更新当前最短路径及距离
		if (!final[w] && (min + G.AdjMatrix[v][w]<D[w])) {
			// 修改D[w]和P[w], w∈V-S
			D[w] = min + G.AdjMatrix[v][w];
			for (j = 0; j<G.vexnum; j++) P[w][j] = P[v][j]; //第v行赋值于第w行
			P[w][w] = TRUE;   // P[w] = P[v]+[w]
		}//if
	}//for


	for (int i = 0; i < G.vexnum; ++i){
		printf( "第%d个点离%d最近%d\n", i, v0, D[i] );
	}
	//如果要打印路径的话，有点费事！！！！
} // ShortestPath_DIJ
int main(){
	while (1){
		MGraph G;
		CreateDN(G);
		OutputAdjMatrix(G);//???????????????????????????添加跳出条件
		printf( "输入出发顶点序号:" );
		int v0;
		scanf( "%d", &v0 );
		p P; d D;

		ShortestPath_DIJ(G, v0, P, D);
	}
	return 0;
}
