//题目网址   http://blog.csdn.net/Frankiller/article/details/7766504 我这个也可以称得上是神级代码了，耶！！
#include<iostream>
using namespace std;
struct Node{
	Node* lLink;
	Node* rLink;
	Node(){
		lLink = NULL; rLink = NULL;
	}
};
int CreateTree(Node* &p){
	int lw, l, rw, r;
	cin >> lw >> l >> rw >> r;
	p = new Node;
	if (!lw){ lw = CreateTree(p->lLink); }
	if (!rw){ rw = CreateTree(p->rLink); }
	if ((l*lw != r*rw) || lw == -1 || rw==-1)return -1;
	return lw + rw;
}
int main(){
	int n;
	cin >> n;
	while (n--){
		Node* head;
		int a = CreateTree(head);
		if (a == -1) cout << "NO" << endl;
		else         cout << "YES" << endl;
		if (n) cout << endl;
	}
	return 0;
}