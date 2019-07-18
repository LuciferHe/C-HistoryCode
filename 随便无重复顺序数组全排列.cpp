#include<stdio.h>

const int N = 10000;


void print_permutation(int n, int * A, int cur, int * p) {
	int i, j;
	if(cur == n)
	{
		for(i = 0; i < n; i++) printf("%d ", A[i]);
		printf("\n");
	}
	else for(i = 0; i < n; i++)
	{
		int ok = 1;
		for(j = 0; j < cur; j++)
			if(A[j] == p[i]) ok = 0;
		if(ok)
		{
			A[cur] = p[i];
			print_permutation(n, A, cur+1, p);
		}
	}
}

int main() {
	const int n = 10;
	int p[n];
	for(int i = 1; i <= n; i++)
		p[i-1] = 2*i - 1;

	int cur = 0;
	int A[N]={0};
	print_permutation(n, A, cur, p);
}