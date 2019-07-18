#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(int item){
	cout << item << " ";
}

int main(){
	vector<int> v;
	for (int i = 1; i < 20; ++i){
		v.push_back(i);
	}
	for_each(v.begin(), v.end(),print);
	return 0;
}