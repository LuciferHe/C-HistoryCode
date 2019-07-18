#include<stdio.h>

const int N = 10000;


void print_permutation(int n, int * A, int cur) {
	int i, j;
	if(cur == n)
	{
		for(i = 0; i < n; i++) printf("%d ", A[i]);
		printf("\n");
	}
	else for(i = 1; i <= n; i++)
	{
		int ok = 1;
		for(j = 0; j < cur; j++)
			if(A[j] == i) {ok = 0; break;}
		if(ok)
		{
			A[cur] = i;
			print_permutation(n, A, cur+1);
		}
	}
}

int main() {
	int n;
	while(scanf("%d", &n)==1 && n) {
		int cur = 0;
		int A[N]={0};
		print_permutation(n, A, cur);
	}
}