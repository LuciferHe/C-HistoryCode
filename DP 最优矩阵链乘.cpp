#include<stdio.h>
#include<string.h>

const int MAXN = 100;
const int INF = 2147483647;
int dp[MAXN][MAXN];
int M[MAXN];
int n;

int min(int a, int b){ return (a<b?a:b); }

int DP(int i,int j){
	int t, k;
	int &ans = dp[i][j];
	if (ans + 1) return ans;
	t = j - i;
	if (t == 0){dp[i][j] = 0;}
	else if (t == 1){ dp[i][j] = M[i - 1] * M[i] * M[j]; }
	else{
		ans = INF;
		for (k = i; k < j; ++k){
			t = DP(i, k) + DP(k + 1, j) + M[i - 1] * M[k] * M[j];
			ans = min(ans,t);
		}
	}
	return ans;
}

int main(){
	int i;
	while (scanf("%d",&n) != EOF){
		memset(M,0,sizeof(M));
		memset(dp, -1, sizeof(dp));
		for (i = 0; i <=n; ++i) scanf("%d",&M[i]);
		printf("%d\n",DP(1,n));
	}
	return 0;
}