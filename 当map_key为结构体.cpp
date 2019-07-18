#include<cstdio>
#include<map>
using namespace std;

struct Node{
	int x, y;
	Node(int xx = 0, int yy = 0) :x(xx), y(yy){}
	bool operator < (Node const &A)const{
		return (x<A.x || (x==A.x && y<A.y));
	}
};

map<Node, int> MP;

int main(){
	int i;
	for (i = 0; i < 10; ++i){
		MP[Node(i, i + 1)] = i*i;
	}
	map<Node, int>::iterator iter = MP.begin();
	while (iter != MP.end()){
		printf("x:%d  y:%d  value:%d\n\n",iter->first.x,iter->first.y,iter->second);
		++iter;
	}
	return 0;
}