//不知道为什么，输入超过44，两个函数的结果就不一样，可能是溢出的原因，或者调用栈之类的!!!!!
/*
题目标题: 第39级台阶

小明刚刚看完电影《第39级台阶》，离开电影院的时候，他数了数礼堂前的台阶数，恰好是39级!

站在台阶前，他突然又想着一个问题：

如果我每一步只能迈上1个或2个台阶。先迈左脚，然后左右交替，最后一步是迈右脚，也就是说一共要走偶数步。那么，上完39级台阶，有多少种不同的上法呢？


请你利用计算机的优势，帮助小明寻找答案。
*/
#include<iostream>
#include<cstring>
using namespace std;
const long long int MAXN = 10000;
long long unsigned int C[MAXN][2] = {0};

long long unsigned int Caculate(int a, int b){
	long long unsigned int temp = 0;
	long long unsigned int max = a + b;
	long long unsigned int min = a < b ? a : b;
	min = (max - min) < (min) ? (max - min) : min;
	if (!min) return 1;
	long long unsigned int t1 = 1;
	long long unsigned int t2 = 1;
	for (unsigned int i = 0; i < min; ++i){
		t1 *= (min - i);
		t2 *= (max - i);
	}
	temp = t2 / t1;
	return temp;
}

long long unsigned int fun(int n){
	long long unsigned int sum = 0;
	for (int i = 0; i <= (n / 2); ++i){
		if (((n - 2 * i) + i) % 2 == 0){
			sum += Caculate(n - 2 * i, i);
		}
	}
	return sum;
}

long long unsigned int fun2( int n ){//n>=2
	memset(C,0,sizeof(C));
	C[0][1] = C[1][0] = 1;
	for (int i = 2; i <= n; ++i){
		C[i][0] = C[i - 1][1] + C[i - 2][1];
		C[i][1] = C[i - 1][0] + C[i - 2][0];
	}
	return C[n][1];
}
int main(){
	int n;
	while (cin >> n){
		cout << fun(n) << endl;
		cout << fun2(n) << endl;
	}
	return 0;
}