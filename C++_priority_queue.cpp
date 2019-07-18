#include <iostream>
#include <queue>
using namespace std;
struct Node{
	int x, y;
}node;
bool operator<(Node a, Node b){//该操作符 用来判断优先级 a<b 是否为true.
	if (a.x == b.x) return a.y>b.y;//在x相同时，y大的优先级  小
	return a.x>b.x;//否则，x大的优先级小
	//优先级最大的在队列的顶部
}
int main(){
	priority_queue<Node>q;
	for (int i = 0; i<10; i++){
		node.x = i;
		node.y = 10 - i / 2;
		printf("Push x:%d  y:%d\n",node.x,node.y);
		q.push(node);
	}
	while (!q.empty()){
		cout <<"Pop "<< q.top().x << ' ' << q.top().y << endl;
		q.pop();
	}
	return 0;
}


/*
#include <iostream>
#include <queue>
using namespace std;
struct Node{
	int x, y;
}node;
struct cmp{
	bool operator()(Node a, Node b){
		if (a.x == b.x) return a.y>b.y;
		return a.x>b.x;
	}
};

int main(){
	priority_queue<Node, vector<Node>, cmp>q;
	for (int i = 0; i<10; i++){
		node.x = i;
		node.y = 10 - i / 2;
		q.push(node);
	}
	while (!q.empty()){
		cout << q.top().x << ' ' << q.top().y << endl;
		q.pop();
	}
	return 0;
}

*/