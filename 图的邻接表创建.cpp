//#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>

const int MAXN = 1000;

typedef struct VNode{
	int data;
	VNode * next;
}VNode;

typedef struct ArcNode{
	char vex;
	VNode * firstArc;
}ArcNode;

typedef struct MGraph{
	int arcNum, vexNum;
	//int weight;
	ArcNode arcNode[MAXN];
}MGraph;

int CreateGraph(MGraph &G);
int OutputGraph(MGraph &G);
int LocateVex(MGraph &G, char c);

int LocateVex(MGraph &G, char c){
	int i = 0;
	for (i = 0; i < G.vexNum; i++){
		if (c == G.arcNode[i].vex){
			return i;
		}
	}
	printf("未找到相应顶点\n");
	return -1;
}


int CreateGraph(MGraph &G){
	printf("请输入图的顶点数：");
	scanf("%d", &G.vexNum);
	printf("请输入图的边数：");
	scanf("%d", &G.arcNum);

	int i = 0;
	for (i = 0; i<G.vexNum; i++){
		printf("Vex[%d]:", i + 1);

		G.arcNode[i].vex = getchar();
		while (G.arcNode[i].vex == '\n')
		{
			G.arcNode[i].vex = getchar();
		}
		getchar();
		G.arcNode[i].firstArc = NULL;
	}//for

	printf("顶点输入完毕\n");

	for (i = 0; i < G.arcNum; i++){
		char p, q;
		printf("请输入第%d条弧的头尾结点( 如:A B形式) ：", i + 1);
		p = getchar();
		getchar();
		q = getchar();
		getchar();
		int m = -1, n = -1;
		m = LocateVex(G, p);
		n = LocateVex(G, q);

		VNode * pointer = (VNode*)malloc(sizeof(VNode));
		pointer->data = n;
		pointer->next = NULL;

		if (G.arcNode[m].firstArc == NULL){
			G.arcNode[m].firstArc = pointer;
		}
		else{
			VNode * pointerTemp = G.arcNode[m].firstArc;
			while (pointerTemp->next != NULL){
				pointerTemp = pointerTemp->next;
			}
			pointerTemp->next = pointer;
		}
	}//for
	return 1;
}//CreateGraph

int OutputGraph(MGraph &G){
	int i = 0;
	printf( "邻接表输出如下：\n" );
	for (i = 0; i < G.vexNum; i++){
		printf( "%c   ", G.arcNode[i] );
		VNode * temp = G.arcNode[i].firstArc;
		while (temp != NULL){
			printf( "%d   ", temp->data );
			temp = temp->next;
		}//while
		printf( "\n" );
	}//for

	printf( "\n输出完毕\n" );
	return 0;
}


int main(){
	MGraph G;
	CreateGraph(G);
	OutputGraph(G);
	return 0;
}