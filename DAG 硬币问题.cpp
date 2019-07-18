//题目：有n种硬币，面值分别为V1,V2,...Vn,每种都有无限多。给定非负整数S，可以选用多少个硬币，使得面值之和恰好为S？输出硬币数目的最小值和最大值！
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100;
int n, S, V[MAXN], d[MAXN],vis[MAXN];
const int INF = 100000000;

int max(int a, int b){
	return (a > b ? a : b);
}

int min(int a, int b){
	return (a < b ? a : b);
}
int dpmax(int S) {
	if (vis[S] || S==0) return d[S];
	vis[S] = 1;
	int &ans = d[S];
	ans = -INF;
	for (int i = 1; i <= n; ++i) {
		if (S >= V[i]) ans = max(ans, dpmax(S - V[i]) + 1);
	}
	return ans;
}

int dpmin(int S) {
	if (vis[S] || S == 0) return d[S];
	vis[S] = 1;
	int &ans = d[S];
	ans = INF;
	for (int i = 1; i <= n; ++i) {
		if (S >= V[i]) ans = min(ans, dpmax(S - V[i]) + 1);
	}
	return ans;
}
void print_ans(int S){//打印字典序最小方案
	for (int i = 1; i <= n; ++i){
		if (S >= V[i] && d[S] == (d[S - V[i]] + 1)){
			cout << i<<" ";
			print_ans(S-V[i]);
			break;
		}
	}
}
int main() {
	memset(d, 0, sizeof(d));
	memset(V, 0, sizeof(V));
	memset(vis, 0, sizeof(vis));
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) {
		cin >> V[i];
	}
	cout << dpmax(S) << endl;
	print_ans(S);
	cout << endl;

	memset(d, 0, sizeof(d));
	memset(vis, 0, sizeof(vis));
	cout << dpmin(S) << endl;
	print_ans(S);
	cout << endl;
	return 0;
}






递推：

#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100;
int n, S, V[MAXN], Min[MAXN], Max[MAXN], min_path[MAXN], max_path[MAXN];
const int INF = 100000000;

int max(int a, int b){
	return (a > b ? a : b);
}

int min(int a, int b){
	return (a < b ? a : b);
}

void print_ans(int* d,int S){//打印最短路径 字典序最小方案
	while (S){
		cout << d[S] << " ";
		S -= V[d[S]];
	}
}
int main() {
	memset(V, 0, sizeof(V));
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) {
		cin >> V[i];
	}
	Min[0] = Max[0] = 0;
	for (int i = 1; i <= S; ++i){
		Min[i] = INF; Max[i] = -INF;
	}

	for (int i = 1; i <= S; ++i){
		for (int j = 1; j <= n; ++j){
			if (i >= V[j]){
				if (Min[i] > (Min[i - V[j]] + 1)){
					Min[i] = Min[i - V[j]] + 1;
					min_path[i] = j;
				}

				if (Max[i] < (Max[i - V[j]] + 1)){
					Max[i] = Max[i - V[j]] + 1;
					max_path[i] = j;
				}

			}
		}
	}

	cout << Max[S] << " " << Min[S]<<endl;
	print_ans(max_path, S);
	cout << endl;
	print_ans(min_path, S);
	cout << endl;
	return 0;
}