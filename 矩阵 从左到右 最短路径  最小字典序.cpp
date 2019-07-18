#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 5;
const int INF = 0x7fffffff;

typedef struct{
	int value;
	int choice;
}Matrix;

Matrix M[MAXN][MAXN];
int dp[MAXN][MAXN];
int R, C;
int minPath;
int minK;

void DP(){
	int i, j, k;
	for (i = C; i >=1; --i){
		for (j = 1; j <= R; ++j){
			int dir[3] = {j-1,j,j+1};
			if (dir[0] < 1) dir[0] = R;
			if (dir[2] > R) dir[2] = 1;
			if (i == C){
				dp[j][i] = M[j][i].value; continue;
			}
			sort(dir,dir+3);
			dp[j][i] = INF;
			for (k = 0; k < 3; ++k){
				if (dp[dir[k]][i + 1] < dp[j][i]){
					dp[j][i] = dp[dir[k]][i + 1];
					M[j][i].choice = dir[k];
				}
			}
			dp[j][i] += M[j][i].value;
		}//for
	}//for
}//DP


int main(){
	int i, j, k, t;
	while (scanf("%d%d",&R,&C) == 2){
		memset(dp, 0, sizeof(dp)); memset(M, 0, sizeof(M)); minPath = INF;
		for (i = 1; i <= R; ++i)for (j = 1; j <= C; ++j)scanf("%d", &M[i][j].value);
		DP();
		for (k = 1; k <= R; ++k){
			if (dp[k][1] < minPath){
				minPath = dp[k][1];
				minK = k;
			}
		}
		printf("%d",minK);
		t = M[minK][1].choice;
		for (i = 2; i <= C; ++i){
			printf(" %d",t);
			t = M[t][i].choice;
		}
		printf("\n%d\n",minPath);
	}
	return 0;
}