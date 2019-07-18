#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

void print(int item){
	cout << item << " ";
}

bool greaterThan5(int item){
	return item > 5;
}

template <class T>
void fillValue(T& vect, int firs, int las){
	if (las >= firs){
		vect.clear();
		for (int i = firs; i <= las; ++i){
			vect.insert(vect.end(), i);
		}
	}
	else{
		cout << "\nError!\n";
	}
}

bool checkEven(int item, bool even){
	if (even){
		return item % 2 == 0;
	}
	else{
		return item % 2 == 1;
	}
}
int main(){
	vector<int> v;
	fillValue(v,1,20);
	for_each(v.begin(), v.end(), print);
	vector<int>::iterator pos1, pos2;
	//第一组 find   寻找符合条件的第一个位置(迭代器)  失败则返回v.end()
	pos1 = find(v.begin(), v.end(),5);
	pos2 = find_if(v.begin(), v.end(), greaterThan5);
	//distance firs + n = las 注意n 可能为负数  通用计算，使用线性或非线性容器
	cout << "\nFisrt position equal 5: " << distance(v.begin(),pos1)  << endl;
	cout << "\nFisrt position greater than 5: " << distance(v.begin(), pos2) << endl;


	//第二组 search_n   搜寻前n个连续匹配值  失败则返回v.end()
	v[3] = 3;
	for_each(v.begin(), v.end(), print);
	pos1 = search_n(v.begin(), v.end(), 2, 3);
	if (pos1 != v.end()){
		cout << "\n连续2个等于3的元素的  起始位置：" << distance(v.begin(), pos1)  << "\n\n";
	}
	else{
		cout << "\nNot Found!\n";
	}
	//greater<int>()  类模板  意思我已经懂  这是有一定编程经历的才能懂得的真正功效
	pos2 = search_n(v.begin(), v.end(), 2, 3, greater<int>());
	if (pos2 != v.end()){
		cout << "\n连续2个大于3的元素的  起始位置：" << distance(v.begin(), pos2) << "\n\n";
	}
	else{
		cout << "\nNot Found!\n";
	}


	//第三组 search 搜寻第一个子区间 
	vector<int> subv;
	fillValue(v, 1, 20);
	fillValue(subv, 1, 4);

	for_each(v.begin(), v.end(), print);
	pos1 = search(v.begin(), v.end(), subv.begin(), subv.end());
	if (pos1 != v.end()){
		cout << "\n与子串匹配的位置："<<distance(v.begin(),pos1) << "\n";
	}
	else{
		cout << "\nNot found!\n";
	}

	bool checkEvenArg[3] = {true, false, true};
	//Tips: 指针 是 特殊迭代器
	pos2 = search(v.begin(), v.end(), checkEvenArg, checkEvenArg + 3, checkEven);
	if (pos2 != v.end()){
		cout << "\n满足偶、奇、偶  子串的位置：" << distance(v.begin(), pos2) << "\n";
	}
	else{
		cout << "\nNot found!\n";
	}

	//第四组 find_end 搜寻最后一个子区间 与 search功能类似  脑补吧
	return 0;
}