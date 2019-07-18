#include<stdio.h>
int main(){
	int a, b, c;
	while (scanf("%d%d%d", &a, &b, &c) != EOF){
		if (a>0 && b>0 && c>0 && a + b > c && a + c > b && b + c > a){
			if (a == b && a == c) 
				printf("3 等边三角形!\n");
			else if (a == b || b == c || a == c) 
				printf("2 等腰三角形!\n");
			else 
				printf("1 普通三角形!\n");
		}
		else{
			printf("0 不是三角形!\n");
		}
	}
	return 0;
}