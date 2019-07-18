/*
样例输入（先序遍历输入）：
1 2 4 0 0 5 0 0 3 6 0 0 7 0 0

样例输出：
7 
6 
3
5
4
2
1
*/
#include<iostream>
#include<stack>

using namespace std;

#define DEBUG 0 //调试超级有用

class Node{
public:
	Node * l;
	Node * r;
	Node( int b = 0 ):c(b){
		r = NULL;
		l = NULL;
	}
	void display(){
		cout << c << endl;
	}
private:
	int c;
};

void CreateTree(Node * &t){
	int a;
	cin >> a;
	if (!a) t = NULL;
	else{
		t = new(Node)(a);
		if(DEBUG) t->display();
		CreateTree(t->l);
		CreateTree(t->r);
	}
}
void PreorderTraversal(Node * root){
	stack<Node*> s1;
	stack<Node*> s2;
	stack<Node*> s3;
	s1.push(root);
	Node * p = root;
	while (!s2.empty() || !s3.empty() || !(p->l==NULL && p->r==NULL)){
		if(p->l)s2.push(p->l);
		if(p->r)s3.push(p->r);
		if (!s2.empty()){
			s1.push(s2.top());
			s2.pop();
			p = s1.top();
		}
		else{
			s1.push(s3.top());
			s3.pop();
			p = s1.top();
		}
	}//while
	cout << endl << endl;
	while (!s1.empty()){
		s1.top()->display();
		s1.pop();
	}
}
void main(){
	Node * root = NULL;
	CreateTree(root);
	PreorderTraversal( root );
}