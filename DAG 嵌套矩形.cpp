//UVA 103  Stacking Boxes

#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

const int MAXK = 32;
const int MAXN = 11;

int K, N, M;

typedef struct{
	int dim[MAXN];
}Obj;

Obj Ob[MAXK];
int G[MAXK][MAXK];
int dp[MAXK];


void CreateG(){
	int i, j, k;
	for (i = 0; i < K; ++i){
		for (j = 0; j < K; ++j){
			for (k = 0; k < N; ++k){
				if (Ob[i].dim[k] <= Ob[j].dim[k])break;
			}
			if (k == N)G[i][j] = 1;
		}
	}
}


int DP(int m){
	if (dp[m])return dp[m];
	dp[m] = 1;
	int i, t;
	for (i = 0; i < K; ++i){
		if (G[m][i]){
			t = DP(i) + 1;
			if (t>dp[m])dp[m] = t;
		}
	}
	return dp[m];
}

void print_ans(int m){
	int i;
	for (i = 0; i < K; ++i){
		if (G[m][i] && dp[m] == (dp[i] + 1)) { print_ans(i); break; }
	}
	if (m == M)printf("%d", m + 1);
	else       printf("%d ", m + 1);
}

int main(){
	int i, j, t;
	int ans;
	while ((scanf("%d%d",&K,&N))!=EOF){
		ans = 0; M = 0;
		memset(Ob,0,sizeof(Ob));
		memset(G, 0, sizeof(G));
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < K; ++i){
			for (j = 0; j < N; ++j){
				scanf("%d",&Ob[i].dim[j]);
			}
			sort(Ob[i].dim, Ob[i].dim + N);
		}

		CreateG();
		for (i = 0; i < K; ++i){
			t = DP(i);
			if (t>ans){ M = i; ans = t; }
		}
		printf("%d\n",ans);
		print_ans(M); printf("\n");
	}
}