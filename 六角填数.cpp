#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define eps 10e-10
#define N 15

int a[N];
bool vis[N];

void dfs(int x){
	if (x == 1 || x == 2 || x == 12){
		dfs(x + 1);
		return;
	}
	if (x > 12){
		int t[6];
		t[0] = a[1] + a[3] + a[6] + a[8];
		t[1] = a[1] + a[4] + a[7] + a[11];
		t[2] = a[2] + a[3] + a[4] + a[5];
		t[3] = a[2] + a[6] + a[9] + a[12];
		t[4] = a[8] + a[9] + a[10] + a[11];
		t[5] = a[12] + a[10] + a[7] + a[5];

		for (int i = 1; i < 6; ++i){
			if (t[i] != t[i - 1])return;
		}
		for (int i = 1; i <= 12; i++)
			cout <<a[i]<<' ' ;
		cout<<endl;
		return;
	}

	for (int i = 1; i < 13; ++i){
		if (!vis[i]){
			vis[i] = 1;
			a[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}


}

int main(){
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	a[1] = 1;
	vis[8] = 1;
	a[2] = 8;
	vis[3] = 1;
	a[12] = 3;

	dfs(1);

	return 0;
}
