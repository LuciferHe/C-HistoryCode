//0-1背包问题
//递归形式
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100;
int n, S, V[MAXN], W[MAXN];

//dp[cur][S]: 将第cur(1...n)~第n个物品放进剩余容量为S的背包中的最大重量
//状态转换方程 dp[cur][S] = max{W[cur] + dp[cur+1][S-V[cur]], dp[cur+1][S]}
//放cur: val1 = W[cur] + dp[cur+1][S-V[cur]]
//不放cur: val2 = dp[cur+1][S]
//dp[cur][S] = max(val1, val2)
//递归较深的话，很费时间和堆栈
int dpmax(int cur, int S) {
	if (!S || cur>n) return 0;
	int ans = dpmax(cur+1,S);
	if (S >= V[cur]){ int t = dpmax(cur + 1, S - V[cur]) + W[cur]; ans = ans > t ? ans : t; }
	return ans;
}


int main() {
	memset(V, 0, sizeof(V));
	memset(W, 0, sizeof(W));
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) {
		cin >> V[i]>>W[i];
	}
	cout << dpmax(1,S) << endl;
	return 0;
}



//递推形式
//d[i][j]表示当前在第i层，背包剩余容量为j时接下来的最大重量和
//
//状态转移方程：d[i][j] = max{d[i+1][j],d[i+1][j-V[i]]+W[i]}
//边界i>n
//从下往上算不就搞定了
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100;
int n, S, V[MAXN], W[MAXN], d[MAXN][MAXN];


int main() {
	memset(V, 0, sizeof(V));
	memset(W, 0, sizeof(W));
	memset(d, 0, sizeof(d));
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) {
		cin >> V[i]>>W[i];
	}
	for (int i = n; i >= 1; --i){
		for (int j = 0; j <= S; ++j){
			d[i][j] = (i==n?0:d[i][j]);//太美了
			if (j >= V[i]){
				int t1 = d[i + 1][j - V[i]] + W[i];
				int t2 = d[i][j];
				d[i][j] = t1 > t2 ? t1 : t2;
			}
		}
	}
	cout << d[1][S] << endl;
	return 0;
}

//从前往后算
//另一种递推
//d[i][j]把前i个物品装到容量为j的背包中的最大总重量
//d[i][j] = max{d[i][j], d[i-1][j-V[i]]+W[i]}
//去掉了V[],W[]两个数组
//改变规划方向 别有洞天
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100;
int n, S, d[MAXN][MAXN];


int main() {
	int V, W;
	memset(d, 0, sizeof(d));
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) {
		cin >> V >> W;
		for (int j = 0; j <= S; ++j){
			d[i][j] = (i==1?0:d[i-1][j]);
			if (j >= V){
				int t1 = d[i-1][j-V] + W;
				int t2 = d[i][j];
				d[i][j] = t1 > t2 ? t1 : t2;
			}
		}
	}
	cout << d[n][S] << endl;
	return 0;
}



//滚动数组  因为计算顺序特殊
//缺点：解的打印变得困难了
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100;
int n, S, d[MAXN];


int main() {
	int V, W;
	memset(d, 0, sizeof(d));
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) {
		cin >> V >> W;
		for (int j = S; j >= 0; --j){
			if (j >= V){
				int t1 = d[j];
				int t2 = d[j-V]+W;
				d[j] = t1 > t2 ? t1 : t2;
			}
		}
	}
	cout << d[S] << endl;
	return 0;
}