#include <stack>
#include <stdio.h>
using namespace std;
stack<int> a;
void ten_to_x(int n, int x){
	while (n){
		a.push(n%x);
		n /= x;
	}
	while (!a.empty()){
		printf("%d",a.top());
		a.pop();
	}
	printf("\n");
}
int main(){
	int n, radix;
	while (scanf_s("%d%d", &n, &radix) == 2){
		ten_to_x(n,radix);
	}
}