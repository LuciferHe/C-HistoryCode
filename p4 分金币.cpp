# include<cstdio>
# include<algorithm>
using namespace std;

const int maxn = 10000 + 10;
int A[maxn], C[maxn], tot, M;

int main(){
	int n, i;
	while(scanf("%d", &n) == 1){
		tot = 0;
		for(i = 1; i <= n; i++)
		{ scanf("%d", &A[i]); tot += A[i]; }

		M = tot / n;
		C[0] = 0;
		for(i = 1; i < n; i++)
			C[i] = C[i-1] + A[i] - M;
		sort(C, C+n);
		int x1 = C[n/2], ans = 0;
		for(i = 0; i < n; i++)
			ans += abs(x1 - C[i]);
		printf("%d\n", ans);
	}
	return 0;
}