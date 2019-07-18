#include<iostream>
#include<cmath>
using namespace std;
#define int64 long long

bool isSquareNumber(int64 n){//完全平方数判定
	/*int64 t , t1, sum;
	int first = 1;
	t = n % 10;//获取个位
	switch (t)
	{
	case 2:
	case 3:
	case 7:
	case 8:return false;//完全平方数个位不可能出现 2 3 7 8
	default:break;
	}
	sum = n;
	while(sum>9){
		t = sum;
		sum = 0;
		while (t){
			sum += (t%10);
			t /= 10;
		}
	}
	switch (sum)
	{
	case 0:
	case 1:
	case 4:
	case 7:
	case 9:break;//完全平方数数字循环累加和只能是0 1 4 7 9
	default:return false;
	}
	t = n % 10;//获取个位
	t1 = n % 100; t1 /= 10;//获取十位
	if (t % 2){//如果该数是  奇数
		if (t1 % 2)return false;//奇数完全平方数十位上不可能是  奇数
		if ((n % 4) != 1)return false;//奇数完全平方数必须是4k+1
	}
	else{
		if (t == 6 && t1 % 2 == 0)return false;//如果完全平方数个位是6,则十位上不可能是  偶数
		if (n % 4)return false;//偶数完全平方数必须是4的整数倍
	}

	for (t = 1; n > 0; t += 2) n -= t;
	return ( n == 0 );*/

	int64 t = (int64)sqrt((double)n);
	return !(n - t*t);
}
int main(){
	int64 l, r;
	int64 countl,countr;
	int64 i;
	while (cin>>l>>r){
		countl = countr = 0;
		cout << endl;
		for (i = r; i > l; --i){
			if (isSquareNumber(i)){
				countr = (int64)sqrt((double)i);
				break;
			}
		}
		for (i = l-1; i > 0; --i){
			if (isSquareNumber(i)){
				countl = (int64)sqrt((double)i);
				break;
			}
		}
		cout << "完全平方数有" << countr - countl << "个。" << endl << endl;
	}
	return 0;
}