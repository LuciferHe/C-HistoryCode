#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print(int item){
	cout << item << " ";
}

bool absLess(int item1, int item2){
	return abs(item1) < abs(item2);
}

int main(){
	vector<int> v;
	for (int i = -6; i < 20; ++i){
		v.push_back(i);
	}
	for_each(v.begin(), v.end(),print);
	int minValue = *min_element(v.begin(), v.end());
	int maxValue = *max_element(v.begin(), v.end());
	int absMin = *min_element(v.begin(), v.end(), absLess);
	int absMax = *max_element(v.begin(), v.end(), absLess);
	cout << "\n\nminValue:" << minValue << "\n\n";
	cout << "\n\nmaxValue:" << maxValue << "\n\n";
	cout << "\n\nabsMin:" << absMin << "\n\n";
	cout << "\n\nabsMax:" << absMax << "\n\n";
	return 0;
}