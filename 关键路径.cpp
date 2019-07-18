//http://blog.csdn.net/chensheng913/article/details/219578
//#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
/*

测试输入：
1
6
8
1,2,3
1,3,2
2,4,2
2,5,3
3,4,4
3,6,3
4,6,2
5,6,1


测试输入：
1
4
5
1,2,3
2,3,4
3,4,1
1,3,6
1,4,2
*/
const int MAXN = 100;

typedef struct EdgeNode{
	int adjVex;
	int duringTime;
	EdgeNode * next;
}EdgeNode;

typedef struct VNode{
	int inD;
	EdgeNode * firstEdge;
}VNode;

typedef struct Graph{
	int vexNum;
	int edgeNum;
	VNode vnode[MAXN];
}Graph;

void CriticalPath();
void CreateGraph(Graph &G);







void CreateGraph(Graph &G){
	//(vexnode* G, int G.vexNum, int G.edgeNum)
	printf( "请输入顶点个数：" );
	scanf( "%d", &G.vexNum );
	printf( "\n" );
	printf("请输入活动个数：");
	scanf("%d", &G.edgeNum);
	printf("\n");

	int begin, end, duttem;
	EdgeNode *p;
	for (int i = 0; i<G.vexNum; ++i)
	{
		G.vnode[i].inD = 0;
		G.vnode[i].firstEdge = NULL;
	}
	printf("某项目的开始到结束在图中的节点输入<vi,vj,dut>\n");
	printf("如：3,4,9 回车表示第三节点到第四节点之间的活动用了9个单位时间\n");
	for (int k = 0; k<G.edgeNum; ++k)
	{
		scanf("%d,%d,%d", &begin, &end, &duttem);
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjVex = end - 1;
		p->duringTime = duttem;
		++G.vnode[end-1].inD;
		p->next = G.vnode[begin - 1].firstEdge;
		G.vnode[begin - 1].firstEdge = p;
	}
}

void CriticalPath(){
	Graph G;
	CreateGraph(G);
	int topologyStack[MAXN] = { 0 };
	int vNodeLast[MAXN] = { 0 };
	int vNodeEarly[MAXN] = { 0 };
	

	int i = 0, j = 0;
	int front = -1, rear = -1;
	for (i = 0; i < G.vexNum; ++i){
		if (G.vnode[i].inD == 0){
			topologyStack[++rear] = i;
		}
	}

	EdgeNode * pEdge;
	int k;

	while (front!=rear)
	{
		++front;
		int j = topologyStack[front];
		pEdge = G.vnode[j].firstEdge;
		while ( pEdge ){
			k = pEdge->adjVex;
			if ((vNodeEarly[j] + pEdge->duringTime) > vNodeEarly[k])
				vNodeEarly[k] = vNodeEarly[j] + pEdge->duringTime;
			--G.vnode[k].inD;
			if (G.vnode[k].inD == 0)
				topologyStack[++rear] = k;
			pEdge = pEdge->next;
		}//while
	}//while

	if (rear + 1 < G.vexNum){
		printf( "存在环，无解\n" );
		return;
	}

	int totalTime = vNodeEarly[G.vexNum - 1];

	for (i = 0; i < G.vexNum; ++i){
		vNodeLast[i] = totalTime;
	}

	for (i = G.vexNum - 2; i != -1; --i){
		j = topologyStack[i];
		pEdge = G.vnode[j].firstEdge;
		while (pEdge){
			k = pEdge->adjVex;
			if ((vNodeLast[k] - pEdge->duringTime) < vNodeLast[j])
				vNodeLast[j] = vNodeLast[k] - pEdge->duringTime;
			pEdge = pEdge->next;
		}//while
	}//for

	int activityEarly = 0, activityLast = 0;
	
	printf("\n\n|  起点  |  终点  |   最早开始时间   |   最迟完成时间   |  差值  |    备注    |\n");
	for (j = 0; j < G.vexNum; j++){
		pEdge = G.vnode[j].firstEdge;
		while (pEdge){
			k = pEdge->adjVex;
			activityEarly = vNodeEarly[j];
			activityLast = vNodeLast[k] - pEdge->duringTime;
			printf("|  %4d  |  %4d  |       %4d       |       %4d       |  %4d  |", j, k, activityEarly, activityLast, activityLast-activityEarly);
			if (activityLast == activityEarly)
				printf("  关键活动  |");
			printf( "\n" );
			pEdge = pEdge->next;
		}//while
	}//for
	return;
}
int main(){
	int choice;
	printf("输入1开始，输入0结束：");
	while (scanf("%d", &choice)==1 && choice)
	{
		switch (choice)
		{
		case 0: break;
		default: CriticalPath(); continue;
		}
		printf("输入1开始，输入0结束：");
	}
	return 0;
}