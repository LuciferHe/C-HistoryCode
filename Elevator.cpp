#include<stdio.h>
using namespace std;

const int N = 10;//总楼层
const int MAXN = N + 5;//MAXN>N
int nPerson[MAXN];//每个楼层的人数
int nMinFloor, nTargetFloor;//nMinFloor所爬楼层总数最小值,nTargetFloor目标楼层
int N1, N2, N3;//N1个人第i楼层以下，N2个人在第i楼层，N3个人第i楼层以上

void input(){
	for (int i = 1; i <= N; ++i){
		scanf("%d", &nPerson[i]);
	}
}

void f(){
	int i;
	for (N1 = 0, N2 = nPerson[1], N3 = 0, i = 2; i <= N; ++i){
		N3 += nPerson[i];
		nMinFloor += (nPerson[i] * (i - 1));
	}
	for (i = 2; i <= N; ++i){
		if (N3>(N1 + N2)){
			nTargetFloor = i;
			nMinFloor += (N1 + N2 - N3);
			N1 += N2;
			N2 = nPerson[i];
			N3 -= nPerson[i];
		}
		else{
			break;
		}
	}//for
}


int main(){
	int Case;
	scanf("%d",&Case);
	while (Case--){
		nTargetFloor = 1;
		nMinFloor = 0;
		input();
		f();
		printf("\nThe target floor is %d, minimun floor is %d.\n\n",nTargetFloor,nMinFloor);
	}//while
}//main