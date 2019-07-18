//证明过程  http://www.cnblogs.com/frog112111/archive/2012/08/19/2646012.html
#include<cstdio>
using namespace std;

void gcd(int a, int b, int& d, int& x, int& y){//扩展欧几里得算法，即找出一对整数使得ax+by=gcd(a,b),一组特解
	if (!b){ d = a; x = 1; y = 0; }
	else{ gcd(b, a%b, d, y, x); y -= (x*(a/b)); }
}

int main(){
	int a, b, d=0, x=0, y=0;
	while (~scanf("%d%d", &a, &b)){
		gcd(a, b, d, x, y);
		printf("d:%d  x:%d  y:%d\n", d, x, y);
	}
	return 0;
}