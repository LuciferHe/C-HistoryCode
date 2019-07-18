//#include"stdafx.h"
#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<cctype>

using namespace std;

//http://acm.uva.es/local/online_judge/search_uva.html

struct Node{
	char data;
	Node *left, *right;
	Node(char c = 0, Node *l = 0, Node *r = 0) :data(c), left(l), right(r){}//构造函数，参数初始化列表
};

Node * Build(char data, Node *left, Node *right){
	Node *father = new Node(data, left, right);//开辟指向节点的指针，并初始化该节点
	return father;
}

int main(){
	int n = 0;
	cin >> n;
	while (n--){
		stack<Node *> s;
		queue<Node *> q;
		string str;
		string ans;
		cin >> str;
		for (int i = 0; i != str.size(); ++i){
			if (islower(str[i])){
				Node *tree = new Node(str[i], 0, 0);//动态新建节点
				s.push(tree);
			}//if
			else{
				Node *r = s.top(); s.pop();
				Node *l = s.top(); s.pop();
				s.push(Build(str[i], l, r));
			}//else
		}//for
		q.push(s.top());
		while (!q.empty()){
			Node *cur = q.front(); q.pop();
			ans += cur->data;
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}//while

		for (int i = ans.size() - 1; i != -1; --i){
			cout << ans[i];
		}//for
		cout << endl;
	}//while
	return 0;
}