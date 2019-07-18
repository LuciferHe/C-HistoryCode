#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

#define M 100100 //最大长度

using namespace std;
typedef struct Node{
    int vex;
    Node* next;
}Child;

Child* head[M];//链表头数组

int f[M][2], Pow[M], visit[M];

//Pow[]权值数组,Pow[i]表示第i个节点的权值 
//f[i][1]保留节点i时最大权值，f[i][0]不保留节点i时的最大权值 
//visit[i]==1表示i点被访问过，visit[i]==0表示节点i未被访问过

//添加边（对称的） 
void addADJ(int u, int v){
    Child *p, *q;
    p = (Child*)malloc(sizeof(Child));
    p->vex = v;
    p->next = head[u];
    head[u] = p;
    q = (Child*)malloc(sizeof(Child));
    q->vex = u;
    q->next = head[v];
    head[v] = q;
}

//动态规划获取结果

void GetResul(int v){
    visit[v] = 1;
    Child *p;
    for (p = head[v]; p != NULL; p = p->next){
        if (visit[p->vex] == 0){
            GetResul(p->vex);
            f[v][1] += f[p->vex][0];
            f[v][0] += max(f[p->vex][0], f[p->vex][1]);
        }
    }
    f[v][1] += Pow[v];
}

int main(){
    int i, j, u, v, n;
    memset(head, NULL, sizeof(head));
    memset(f, 0, sizeof(f));
    memset(visit, 0, sizeof(visit));
    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        scanf("%d", &Pow[i]);
    }
    for (i = 1; i<n; i++){
        scanf("%d%d", &u, &v);
        addADJ(u, v);
    }

    GetResul(1);//从节点1开始进行动态规划
    printf("%d\n", max(f[1][0], f[1][1]));//结果输出
    return 0;
}