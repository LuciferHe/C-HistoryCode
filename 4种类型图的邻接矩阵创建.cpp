/*
无向图UDG
2( 改为0就是有向图 )
4
4
A
B
C
D
A
B
B
C
C
A
C
D


无向网
1（改为1就是有向网）
4
4
A
B
C
D
A
B
3
B
C
4
C
A
5
C
D
3

*/
#include"stdafx.h"
#include<stdio.h>
#include<string.h>


const int MAXN = 100;

typedef enum { DG, DN, UDG, UDN }GraphKind;

typedef struct ArcCell{
	char A;
	char B;
	int num;
}ArcCell;

typedef struct{
	char vexs[MAXN];
	int AdjMatrix[MAXN][MAXN];
	int vexnum, arcnum;
	GraphKind kind;
}MGraph;

int CreateDG(MGraph &G);
int CreateDN(MGraph &G);
int CreateUDG(MGraph &G);
int CreateUDN(MGraph &G);
int LocateVex(MGraph G, char V);
void OutputAdjMatrix(MGraph G);






void OutputAdjMatrix(MGraph G){
	int i = 0, j = 0;
	for (i = -1; i < G.vexnum; i++){
		if (i == -1) printf("%12s", " ");
		else{
			printf("%12c", G.vexs[i]);
		}
	}//for
	printf("\n");
	for (i = 0; i < G.vexnum; i++){
		printf("%12c", G.vexs[i]);
		for (j = 0; j < G.vexnum; j++){
			printf("%12d", G.AdjMatrix[i][j]);
		}//for
		printf("\n");
	}//for
}
int LocateVex(MGraph G, char V){
	int i = 0;
	for (i = 0; i < G.vexnum; i++){
		if (G.vexs[i] == V)
			return i;
	}
	return -1;
}



int CreateDG(MGraph &G) {
	int i, j, k;
	char  v1, v2;
	printf("G.vexnum :");  scanf("%d", &G.vexnum);
	printf("G.arcnum :");   scanf("%d", &G.arcnum);
	getchar();  //加上此句getchar()!!
	// scanf("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);      
	for (i = 0; i<G.vexnum; i++) {
		printf("G.vexs[%d] : ", i);
		scanf("%c", &G.vexs[i]);
		getchar();
	} // 构造顶点向量
	memset(G.AdjMatrix, 0, sizeof(G.AdjMatrix));

	for (k = 0; k<G.arcnum; ++k) {  // 构造邻接矩阵
		printf("v1 (char) : ");  scanf("%c", &v1); getchar();
		printf("v2 (char) : ");  scanf("%c", &v2); getchar();// 输入一条边依附的顶点及权值

		i = LocateVex(G, v1);  j = LocateVex(G, v2);		// 确定v1和v2在G中位置

		G.AdjMatrix[i][j] = 1;                
	}//for
	return 1;
} // CreateDG

int CreateDN(MGraph &G) {//  算法 7.2
	// 采用数组（邻接矩阵）表示法，构造无向网G。
	int i, j, k, w;
	char  v1, v2;
	printf("G.vexnum :");  scanf("%d", &G.vexnum);
	printf("G.arcnum :");   scanf("%d", &G.arcnum);
	getchar();  //加上此句getchar()!!
	
	for (i = 0; i<G.vexnum; i++) {
		printf("G.vexs[%d] : ", i);
		scanf("%c", &G.vexs[i]);
		getchar();
	} // 构造顶点向量
	memset(G.AdjMatrix, 2147483647, sizeof(G.AdjMatrix));

	for (k = 0; k<G.arcnum; ++k) {  // 构造邻接矩阵
		printf("v1 (char) : ");  scanf("%c", &v1); getchar();
		printf("v2 (char) : ");  scanf("%c", &v2); getchar();
		printf("w (int) : ");   scanf("%d", &w); getchar();	// 输入一条边依附的顶点及权值

		i = LocateVex(G, v1);  j = LocateVex(G, v2);// 确定v1和v2在G中位置

		G.AdjMatrix[i][j] = w;                // 弧<v1,v2>的权值
	}//for
	return 1;
} // CreateDN

int CreateUDG(MGraph &G) {//  算法 7.2
	// 采用数组（邻接矩阵）表示法，构造无向网G。
	int i, j, k;
	char  v1, v2;
	printf("G.vexnum :");  scanf("%d", &G.vexnum);
	printf("G.arcnum :");   scanf("%d", &G.arcnum);
	getchar();  //加上此句getchar()!!
	// scanf("%d,%d,%d",&G.vexnum, &G.arcnum, &IncInfo);      
	for (i = 0; i<G.vexnum; i++) {
		printf("G.vexs[%d] : ", i);
		scanf("%c", &G.vexs[i]);
		getchar();
	} // 构造顶点向量
	memset(G.AdjMatrix, 0, sizeof(G.AdjMatrix));

	for (k = 0; k<G.arcnum; ++k) {  // 构造邻接矩阵
		printf("v1 (char) : ");  scanf("%c", &v1); getchar();
		printf("v2 (char) : ");  scanf("%c", &v2); getchar();// 输入一条边依附的顶点及权值

		i = LocateVex(G, v1);  j = LocateVex(G, v2);// 确定v1和v2在G中位置

		G.AdjMatrix[i][j] = 1;                // 弧<v1,v2>的权值
		
		G.AdjMatrix[j][i] = G.AdjMatrix[i][j]; // 置<v1,v2>的对称弧<v2,v1>
	}//for
	return 1;
} // CreateUDG

int CreateUDN(MGraph &G) {//  算法 7.2
	// 采用数组（邻接矩阵）表示法，构造无向网G。
	int i, j, k, w;
	char  v1, v2;
	printf("G.vexnum :");  scanf("%d", &G.vexnum);
	printf("G.arcnum :");   scanf("%d", &G.arcnum);
	getchar();  //加上此句getchar()!!
	for (i = 0; i<G.vexnum; i++) {
		printf("G.vexs[%d] : ", i);
		scanf("%c", &G.vexs[i]);
		getchar();
	} // 构造顶点向量
	memset(G.AdjMatrix, 2147483647, sizeof(G.AdjMatrix));

	for (k = 0; k<G.arcnum; ++k) {  // 构造邻接矩阵
		printf("v1 (char) : ");  scanf("%c", &v1); getchar();
		printf("v2 (char) : ");  scanf("%c", &v2); getchar();
		printf("w (int) : ");   scanf("%d", &w); getchar();// 输入一条边依附的顶点及权值

		i = LocateVex(G, v1);  j = LocateVex(G, v2);// 确定v1和v2在G中位置

		G.AdjMatrix[i][j] = w;                // 弧<v1,v2>的权值
		
		G.AdjMatrix[j][i] = G.AdjMatrix[i][j]; // 置<v1,v2>的对称弧<v2,v1>
	}//for
	return 1;
} // CreateUDN

int CreateGraph(MGraph &G){
	printf( "请输入图的类型：" );
	while (scanf("%d", &G.kind) == 1){  //???????????
		printf( "\n" );
		switch (G.kind)
		{
		case DG: CreateDG(G); break;
		case DN: CreateDN(G); break;
		case UDG: CreateUDG(G); break;
		case UDN: CreateUDN(G); break;
		default: printf( "Wrong Input!\n" ); break;
		}//switch
		OutputAdjMatrix(G);
		printf( "\n\n继续请输入图的类型：" );
	}//while
	return 1;
}//CreateGraph

int main(){
	MGraph G;
	CreateGraph(G);
	return 0;
}
