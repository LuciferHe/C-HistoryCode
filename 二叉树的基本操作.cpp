//  1 2 4 0 6 0 0 5 0 8 9 0 0 0 3 0 7 0 0
#include<iostream>
#include <queue>
//#define DEBUG 1;
using namespace std;

const int MAXN = 100;

void TreeTest();

class Tree{
public:
	Tree(){
		head = NULL;
	}

	struct Node{
		int data;
		Node* l;
		Node* r;
		Node(int d = 0, Node* left = NULL, Node* right = NULL) :data(d), l(left), r(right){}
	};


	//先序创建
	void CreateCLR(Node* &);
	void CreateCLR(){
		cout << "按照先序遍历序列创建（含0）！" << endl;
		CreateCLR(head);
	}
	//交换左右子树
	void ExchangeLR(Node* &);
	void ExchangeLR(){
		ExchangeLR(head);
	}
	void Traversal(){
		int a;
		cout << "Enter choice:";
		cin >> a;
		cout << endl;
		switch (a)
		{
		case 1: cout << "-------------PreOrder-----------" << endl;
			PreTraversal(head); cout << endl; break;
		case 2: cout << "-------------InOrder-----------" << endl;
			InTraversal(head); cout << endl; break;
		case 3: cout << "-------------PostOrder-----------" << endl;
			PostTraversal(head); cout << endl; break;
		case 4: cout << "-------------FloorOrder-----------" << endl;
			FloorTraversal(head); cout << endl; break;
		default:cout << "Error!" << endl; break;
		}
	}
	//先序遍历
	void PreTraversal(Node*);
	//中序遍历
	void InTraversal(Node*);
	//后序遍历
	void PostTraversal(Node*);
	//层序遍历
	void FloorTraversal(Node*);


	//最长路径
	int max(Node*);
	int max(){
		return max(head);
	}

	//树的高度
	int deep(Node*);
	int deep(){
		return deep(head);
	}
private:
	Node * head;
};

void Tree::CreateCLR(Node* &p){
	int d;
	cout << "Enter num:";
	cin >> d;
	if (d){
		Node *p1 = new(Node)(d, NULL, NULL);
		if (head == NULL){
			head = p1;
		}
		else{
			p = p1;
		}
		CreateCLR(p1->l);
		CreateCLR(p1->r);
	}
}
void Tree::ExchangeLR(Node* &p){
	if (p != NULL){
		Node* temp;
		temp = p->l;
		p->l = p->r;
		p->r = temp;
		if (p->l != NULL) ExchangeLR(p->l);
		if (p->r != NULL) ExchangeLR(p->r);
	}
}
void Tree::PreTraversal(Node* p){
	if (p){
		cout << p->data << " ";
		PreTraversal(p->l);
		PreTraversal(p->r);
	}
}
void Tree::InTraversal(Node* p){
	if (p){
		InTraversal(p->l);
		cout << p->data << " ";
		InTraversal(p->r);
	}
}
void Tree::PostTraversal(Node* p){
	if (p){
		PostTraversal(p->l);
		PostTraversal(p->r);
		cout << p->data << " ";
	}
}
void Tree::FloorTraversal(Node* p){
	queue<Node*>q;
	q.push(p);
	while (!q.empty()){
		Node * temp = q.front();
		if (temp->l) q.push(temp->l);
		if (temp->r) q.push(temp->r);
		cout << temp->data << " ";
		q.pop();
	}
}
int Tree::max(Node* p){
	if (p){
		int a, b;
		return p->data + ((a = max(p->l)) >= (b = max(p->r)) ? a : b);
	}
	else return 0;
}
int Tree::deep(Node* p){
	if (p){
		int a, b;
		return 1 + ((a = deep(p->l))>(b = deep(p->r)) ? a : b);
	}
	else return 0;
}
void main(){
	TreeTest();
}
void TreeTest(){
	Tree tree;
	tree.CreateCLR();
	tree.Traversal();
	tree.ExchangeLR();
	tree.Traversal();
	cout << "Max is : " << tree.max() << endl;
	cout << "Deep is : " << tree.deep() << endl;
}