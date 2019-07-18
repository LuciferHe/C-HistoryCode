//求直线ax+by+c = 0上有多少个整数点(x,y)满足[x1,x2] && [y1,y2] 教材179页

#include<cstdio>
using namespace std;
#define DEBUG 0
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

void gcd(int a, int b, int& d, int& x, int& y){//扩展欧几里得算法，即找出一对整数使得ax+by=gcd(a,b),一组特解
	if (!b){ d = a; x = 1; y = 0; }
	else{ gcd(b, a%b, d, y, x); y -= (x*(a/b)); }
}

int isOk(int a, int b, int c, int x, int y){
	return ( a*x + b*y + c == 0);
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
#endif
	int a, b, c, d=0, x=0, y=0;
	while (~scanf("%d%d%d", &a, &b, &c)){
		int x1, x2,y1,y2;
		scanf("%d%d%d%d",&x1, &x2, &y1, &y2);
		gcd(a, b, d, x, y);
		if (c%d == 0){
			x *= (-c / d);
			y *= (-c / d);
			int ta = a / d;
			int tb = b / d;
			int mink = MIN(((x1 - x) / tb) - 1, ((y1 - y) / (-ta)) - 1);
			int maxk = MAX(((x2 - x) / tb) + 1, ((y2 - y) / (-ta)) + 1);
			int flag = 0, count = 0;
			for (int k = mink; k <= maxk; ++k){
				if (x1 <= (x + k*tb) && (x + k*tb) <= x2 && y1 <= (y - k*ta) && (y - k*ta)<=y2){
					++count;
					if (DEBUG){
						printf("x' = %d  y' = %d  ", x + k*tb, y - k*ta);
						if (isOk(a, b, c, x + k*tb, y - k*ta)){ printf("  Good\n\n"); }
						else printf("  Bad\n\n");
					}
					flag = 1;
				}
			}
			if (!flag){
				printf("No answer!\n");
			}else{
				printf("count:%d\n",count);
			}
		}
		else{ printf("No answer!\n"); }
	}
	return 0;
}