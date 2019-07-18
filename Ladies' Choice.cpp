/*
Sample Input
1
 
5
1 2 3 5 4
5 2 4 3 1
3 5 1 2 4
3 4 2 1 5
4 5 1 2 3
2 5 4 1 3
3 2 4 1 5
1 2 4 3 5
4 1 2 5 3
5 3 2 4 1
Sample Output
1
2
5
3
4
*/#include<cstdio>
#include<queue>
using namespace std;

const int maxn = 1000 + 10;

int pref[maxn][maxn], order[maxn][maxn], next[maxn];
int future_husband[maxn], future_wife[maxn];
queue<int> q;

void engage( int man, int woman ){
	int m = future_husband[woman];
	if(m){
		future_wife[m] = 0;
		q.push(m);
	}
	future_wife[man] = woman;
	future_husband[woman] = man;
}

int main(){
	int T;
	int i=0, j=0;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf ("%d", &n);

		for(i = 1; i<= n; i++){
			for(j = 1; j<= n; j++)
				scanf("%d", &pref[i][j]);
			next[i] = 1;
			future_wife[i] = 0;
			q.push(i);
		}

		for(i = 1; i<= n; i++){
			for(j = 1; j<= n; j++){
				int x;
			scanf("%d", &x);
			order[i][x] = j;
		}
		future_husband[i] = 0;
	}

	while(!q.empty()){
		int man = q.front(); q.pop();
		int woman = pref[man][next[man]++];
		if(!future_husband[woman])
			engage(man, woman);
		else if(order[woman][man] < order[woman][future_husband[woman]])
			engage(man, woman);
		else q.push(man);
	}
	while(!q.empty()) q.pop();

	for(i = 1; i <= n; i++)
		printf("%d\n", future_wife[i]);
	if(T) printf("\n");
}
return 0;
}