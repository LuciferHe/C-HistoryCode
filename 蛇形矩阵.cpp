#include<cstdio>
#include<cstring>

int main(){
	int a[100][100];
	int n;
	printf("蛇形矩阵\n\n\n");
	printf("请输入矩阵的阶数：");
	scanf("%d",&n);
	int i=1, j=n;
	int direction = 4;
	int count = 1;
	memset(a,0,sizeof(a));
	while (count<=n*n && a[i][j] == 0){
		a[i][j] = count++;
		int x=i, y=j;
		switch (direction)
		{
		case 1: ++x; break;
		case 2: --y; break;
		case 3: --x; break;
		case 4: ++y; break;
		default: break;
		}
		if (x > n || x < 1 || y > n || y < 1 || a[x][y] != 0){
			++direction; if (direction == 5) direction = 1;
		}
		switch (direction)
		{
		case 1: ++i; break;
		case 2: --j; break;
		case 3: --i; break;
		case 4: ++j; break;
		default: break;
		}
	}//while

	printf("\n\n蛇形矩阵如下:\n\n");
	for (i = 1; i <= n; ++i){
		for (j = 1; j <= n; ++j){
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}