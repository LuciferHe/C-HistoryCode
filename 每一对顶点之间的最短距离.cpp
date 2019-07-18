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
*/

#include"stdafx.h"
#include<windows.h>
#include<windef.h>
#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
const int MAXN = 50;
const int infinity = 2147483647;   //关于INFINITY有点。。。
class ArcCell{
public:
	int A;
	int B;
	int num;
	ArcCell(){
		A = 0;
		B = 0;
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

typedef BOOL p[MAXN][MAXN][MAXN];
typedef int d[MAXN][MAXN];

//-------函数声明--------
int CreateDN(MGraph &G);
int LocateVex(MGraph G, char V);
void OutputAdjMatrix(MGraph G);
void ShortestPath_FLOYD(MGraph G, p &P, d &D);
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
	int i = 0, j, k, w;
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
void ShortestPath_FLOYD(MGraph G, p &P, d &D) {
	// 算法7.16
	// 用Floyd算法求有向网G中各对顶点v和w之间的最短路径P[v][w]及其
	// 带权长度D[v][w]。若P[v][w][u]为TRUE，则u是从v到w当前求得最
	// 短路径上的顶点。
	int v, w, u, i;
	for (v = 0; v<G.vexnum; ++v)        // 各对结点之间初始已知路径及距离
	for (w = 0; w<G.vexnum; ++w) {
		D[v][w] = G.AdjMatrix[v][w];
		for (u = 0; u<G.vexnum; ++u) P[v][w][u] = FALSE;
		if (D[v][w] < infinity) {     // 从v到w有直接路径
			P[v][w][v] = P[v][w][w] = TRUE;
		}//if
	}//for
	for (u = 0; u<G.vexnum; ++u)
	for (v = 0; v<G.vexnum; ++v)
	for (w = 0; w<G.vexnum; ++w)
	if (D[v][u] + D[u][w] < D[v][w]) {  // 从v经u到w的一条路径更短
		D[v][w] = D[v][u] + D[u][w];
		for (i = 0; i<G.vexnum; ++i)
			P[v][w][i] = (P[v][u][i] || P[u][w][i]);
	}//if

	printf("最短距离矩阵如下:\n");
	for (int i = 0; i < G.vexnum; ++i){
		for (int j = 0; j < G.vexnum; ++j){
			printf("%12d", D[i][j]);
		}
		cout << endl;
	}
} // ShortestPath_FLOYD

int main(){
	while (1){
		MGraph G;
		CreateDN(G);
		OutputAdjMatrix(G);//???????????????????????????添加跳出条件
		p P; d D;

		ShortestPath_FLOYD(G, P, D);
	}
	return 0;
}
