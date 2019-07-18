#include <iostream>
#include <algorithm>
using namespace std;

bool cmp( int a, int b){
	return a >= b;//降序排列
}
int main()
{
	int a[10] = { 0 };
	for (int i = 0; i < 10; i++)
		a[i] = i;
	sort(a + 0, a + 10, cmp);
	//a+0 表示数据起始地址  
	//a+10 表示末尾地址的下一位
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	return 0;
}