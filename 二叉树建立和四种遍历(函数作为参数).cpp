//此程序用来练习C++中——用函数作为参数
//http://zhidao.baidu.com/link?url=v5LtW39nZ2hyghUpk9J9xluzfT3ofoRz_ZSkEV-dQEOom-ZPjik_XRiNeSXLoDmNKMtuA2s51BGQgykGvFnCra
//http://zhidao.baidu.com/link?url=-GGus1TNObC1-LmlY_Y0qM87--98163Y8mIOnRe1rQimc86-4Gp6YeWc8ajgNfgw21xtUeM5TIfy1dbNqm3T7K

# include<stdio.h>
# include<stdlib.h>
# include<queue>

using namespace std;

queue<struct Node *>que;

const int MAXN = 50;

struct Node{
	struct Node * lchild;
	struct Node * rchild;
	char   data;
};

typedef struct Node * BiTNode;
typedef int(*ftype)(BiTNode);

BiTNode Tree;

BiTNode CreateBiTree( BiTNode T ){
	// 按先序次序输入二叉树中结点的值（一个字符），空格字符表示空树，
	// 构造二叉链表表示的二叉树T。
	char ch;
	scanf_s("%c", &ch);
	if (ch == ' ') T = NULL;
	else {
		if (!(T = (BiTNode)malloc(sizeof(BiTNode)))){
			printf("No space!\n");
			exit(-1);
		}//if
		T->data = ch;              // 生成根结点
		T->lchild = CreateBiTree(T->lchild);   // 构造左子树
		T->rchild = CreateBiTree(T->rchild);   // 构造右子树
	}
	return T;
}//CreateBiTree


int Visit( char e ){
	if (e >= 0 && e <= 127) {
		printf("%c", e);
		return 1;
	}
	return 0;
}


int PreOrderTraverse(BiTNode T){
	if (T){
		if (Visit(T->data)){
			PreOrderTraverse(T->lchild);
			PreOrderTraverse(T->rchild);
			return 1;
		}
		return 0;
	}//if
	else {
		if ( T==Tree ) return 0;
		return 1;
	}
}//PreOrderTraverse

int InOrderTraverse(BiTNode T){
	if (T){
		InOrderTraverse(T->lchild);
		if (Visit(T->data)){
			if (InOrderTraverse(T->rchild))
				return 1;
		}//if
		return 0;
	}//if
	else {
		if (T == Tree) return 0;
		return 1;
	}
}//InOrderTraverse


int PostOrderTraverse(BiTNode T){
	if (T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		Visit(T->data);
		return 1;
	}//if
	else {
		if (T == Tree) return 0;
		return 1;
	}
}//PostOrderTraverse

int LevelOrderTraverse(BiTNode T){
	if (T){
		que.push(T);
		while (!que.empty()){
			printf("%c", (que.front())->data);
			if ((que.front())->lchild)  que.push((que.front())->lchild);
			if ((que.front())->rchild)  que.push((que.front())->rchild);
			que.pop();
		}//while
		return 1;
	}//if
	else return 0;
}//LevelOrderTraverse

void deal(BiTNode T, ftype fun){
	fun(T);
}

int main(){
	struct Node a;
	a.data = 0;
	a.lchild = a.rchild = NULL;
	BiTNode temp = &a;
	int choice;
	while ( (Tree=CreateBiTree( temp ))){
		while (1){
			printf("1  PreOrderTraverse\n");
			printf("2  InOrderTraverse\n");
			printf("3  PostOrderTraverse\n");
			printf("4  LevelOrderTraverse\n");
			printf("Please enter your choice: ");
			scanf_s("%d", &choice);
			switch (choice){
			case 1: deal(Tree, PreOrderTraverse); printf("\n"); break;
			case 2: deal(Tree, InOrderTraverse);  printf("\n"); break;
			case 3: deal(Tree, PostOrderTraverse); printf("\n"); break;
			case 4: deal(Tree, LevelOrderTraverse); printf("\n"); break;
			}//switch
		}//while
	}//while
	return 0;
}
