#include<stdio.h>
#include<time.h>

void main(){
	clock_t start, end;
	start = clock();
	printf("开始：%ld\n",start);
	for (int i = 0; i <= 999999999; ++i){
		for (int j = 0; j <= -1; ++j){
			for (int k = 0; k <= -1; ++k){
				int m = 0;
				m++;
			}
		}
	}
	end = clock();
	printf("结束：%ld\n",end);
	printf("%ld(毫秒)\n", (end - start));
	//printf("%.4lf(秒)\n", (double)(end - start)/CLOCKS_PER_SEC);//换成秒
}
