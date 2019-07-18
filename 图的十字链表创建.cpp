//#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>

const int MAXN = 1000;


typedef struct ArcNode{
	int headVex, tailVex;
	ArcNode * hLink, *tLink;
}ArcNode;

typedef struct VNode{
	char data;
	ArcNode * firstIn;
	ArcNode * firstOut;
}VNode;



typedef struct MGraph{
	int arcNum, vexNum;
	//int weight;
	VNode vNode[MAXN];
}MGraph;

int CreateGraph(MGraph &G);
int OutputGraph(MGraph &G);
int LocateVex(MGraph &G, char c);

int LocateVex(MGraph &G, char c){
	int i = 0;
	for (i = 0; i < G.vexNum; i++){
		if (c == G.vNode[i].data){
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

		G.vNode[i].data = getchar();
		while (G.vNode[i].data == '\n')
		{
			G.vNode[i].data = getchar();
		}
		getchar();
		G.vNode[i].firstIn = NULL;
		G.vNode[i].firstOut = NULL;
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

		ArcNode * pointer = (ArcNode*)malloc(sizeof(ArcNode));
		pointer->headVex = m;
		pointer->tailVex = n;
		pointer->hLink = NULL;
		pointer->tLink = NULL;

		ArcNode * pointerTemp = G.vNode[m].firstOut;
		if (pointerTemp == NULL){
			G.vNode[m].firstOut = pointer;
		}
		else{
			while (pointerTemp->hLink != NULL){
				pointerTemp = pointerTemp->hLink;
			}
			pointerTemp->hLink = pointer;
		}


		pointerTemp = G.vNode[n].firstIn;
		if (pointerTemp == NULL){
			G.vNode[n].firstIn = pointer;
		}
		else{
			while (pointerTemp->tLink != NULL){
				pointerTemp = pointerTemp->tLink;
			}
			pointerTemp->tLink = pointer;
		}
	}//for
	return 1;
}//CreateGraph

int OutputGraph(MGraph &G){
	int i = 0;
	printf( "邻接表输出如下：\n" );
	for (i = 0; i < G.vexNum; i++){
		printf( "%c   ", G.vNode[i].data );
		printf( "Out  " );
		ArcNode * temp = G.vNode[i].firstOut;
		while (temp != NULL){
			printf( "%d   ", temp->tailVex );
			temp = temp->hLink;
		}//while

		printf( "In   " );
		temp = G.vNode[i].firstIn;
		while (temp != NULL){
			printf("%d   ", temp->headVex);
			temp = temp->tLink;
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
