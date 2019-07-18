#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(int item){
	cout << item << " ";
}

void multi(int& item){
	item *= 2;
}

bool isEven(int item){
	return item % 2 == 0;
}

int main(){
	vector<int> v;
	for (int i = 1; i < 20; ++i){
		v.push_back(i);
	}
	for_each(v.begin(), v.end(),print);
	int ct = count(v.begin(), v.end(), 4);
	int ctif = count_if(v.begin(), v.end(), isEven);
	cout << "\nNumbers count Equal 4: " << ct << "\n";
	cout << "Even numbers count : " << ctif << "\n";
	return 0;
}