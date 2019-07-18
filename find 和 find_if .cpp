#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(int item){
	cout << item << " ";
}

bool greaterThan5(int item){
	return item > 5;
}

int main(){
	vector<int> v;
	for (int i = 1; i < 20; ++i){
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), print);
	vector<int>::iterator pos1, pos2;
	pos1 = find(v.begin(), v.end(),5);
	pos2 = find_if(v.begin(), v.end(), greaterThan5);
	//distance first + n = last 注意n 可能为负数  通用计算，使用线性或非线性容器
	cout << "\n\n" << distance(v.begin(),pos1) + 1 << endl;
	cout << "\n\n" << distance(v.begin(), pos2) + 1 << endl;
	return 0;
}