//带权DAG
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100;
int n, S, V[MAXN], W[MAXN],d[MAXN], vis[MAXN];
const int INF = 100000000;

int max(int a, int b){
	return (a > b ? a : b);
}

int dpmax(int S) {
	if (vis[S] || S == 0) return d[S];
	vis[S] = 1;
	int &ans = d[S];
	ans = -INF;
	for (int i = 1; i <= n; ++i) {
		if (S >= V[i]) ans = max(ans, dpmax(S - V[i]) + W[i]);
	}
	return ans;
}

void print_ans(int S){//打印字典序最小方案
	for (int i = 1; i <= n; ++i){
		if (S >= V[i] && d[S] == (d[S - V[i]] + W[i])){
			cout << i << " ";
			print_ans(S - V[i]);
			break;
		}
	}
}
int main() {
	memset(d, 0, sizeof(d));
	memset(V, 0, sizeof(V));
	memset(W, 0, sizeof(W));
	memset(vis, 0, sizeof(vis));
	cin >> n >> S;
	for (int i = 1; i <= n; ++i) {
		cin >> V[i]>>W[i];
	}
	cout << dpmax(S) << endl;
	print_ans(S);
	cout << endl;
	return 0;
}