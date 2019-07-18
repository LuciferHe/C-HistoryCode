/*
Vector专题
它是C++中可以取代C中的数组，效率更高，更安全。
头文件：#include <vector>
Vector：Vector 是一个类模板。不是一种数据类型。 Vector<int>是一种数据类型。
缺点（与数组一样）：需要容器在head和tail高效的插入和删除，或者在任何位置高效的删除和插入操作，那么你可能使用deque或者list更合适。
使用原则：
尽量使用vector代替c风格的数组或者CArray；
尽量使用算法代替手工写的循环；
尽量使用vector本身的函数代替其他泛型算法；


一：定义和初始化举例
vector<string> v1;         // 创建空容器，其对象类型为string类
vector<string> v2(10);     // 创建有10个具有初始值（即空串）的string类对象的容器
vector<string> v3(5, "hello"); // 创建有5个值为“hello”的string类对象的容器
vector<string> v4(v3.begin(), v3.end()); // v4是与v3相同的容器（完全复制）Vector<T> v4(n);  //v4含有n个值为0的元素
二：操作
1.    v.push_back(t)       在数组的最后添加一个值为t的数据
2.    v.size()             返回容器中元素个数
3.    v.empty()            判断vector是否为空
4.    v[n]                 返回v中位置为n的元素
5.    v1=v2                把v1的元素替换为v2元素的副本
6.    v1==v2               判断v1与v2是否相等
7.    ！=、<、<=、>、>=    保持这些操作符惯有含义

举例：
vector<string> v1;         // 创建空容器，其对象类型为string类
vector<string> v2(10);     // 创建有10个具有初始值（即空串）的string类对象的容器
vector<string> v3(5, "hello"); // 创建有5个值为“hello”的string类对象的容器
vector<string> v4(v3.begin(), v3.end()); // v4是与v3相同的容器（完全复制）

vector的操作（下面的函数都是成员函数）
empty() const;             // 如果为容器为空，返回true；否则返回false
size() const;              // 返回容器中元素个数
size_type capacity() const;// 容器能够存储的元素个数，有：capacity() >= size()
void resize(size_type n, T x = T());   // 确保返回后，有：size() == n；如果之前size()<n，那么用元素x的值补全。
front();                   // 返回容器中第一个元素的引用（容器必须非空）
back();                    //返回容器中最后一个元素的引用（容器必须非空）
void pop_back();           // 弹出容器中最后一个元素（容器必须非空）


// 注：下面的插入和删除操作将发生元素的移动（为了保持连续存储的性质），所以之前的迭代器可能失效
iterator erase(iterator it);           // 删除指定元素，并返回删除元素后一个元素的位置（如果无元素，返回end()）
iterator erase(iterator first, iterator last); // 注意：删除元素后，删除点之后的元素对应的迭代器不再有效。
void clear() const;                    // 清空容器
iterator begin();
iterator end();
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int a)
{
	cout << a << "\t";
}

bool cmp( int a, int b ){
	return a >= b;//降序
}

int main()
{
	vector<int> a;
	for (int i = 0; i < 10; ++i){
		a.push_back(i);
	}
	for (int i = 0; i < a.size(); ++i){
		cout << "The "<<i+1<<"st is "<<a[i] << endl;
	}
	

	a.erase(a.begin()+5,a.end());//这里的end都和队列rear指针的定义一样

	cout << "\n\nOutput ways2:" << endl;
	for (vector<int>::const_iterator it = a.begin(); it != a.end(); ++it){//最好用 !=,因为很多非随机迭代器不支持<操作
		cout << *it << endl;
	}

	cout << "\n\n\n";
	sort(a.begin(),a.end(),cmp);
	for_each(a.begin(), a.end(), print);//algotithm的泛型算法for_each打印  简洁  需要写一个print函数

	//Part2 二维数组
	cout << "\n\n\n";
	vector<vector<int>> b;
	vector<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);

	vector<int> d;
	d.push_back(4);
	d.push_back(5);
	d.push_back(6);

	b.push_back(c);
	b.push_back(d);

	//输出 b数组
	for (int i = 0; i < b.size(); ++i){
		for (int j=0;j<b[i].size();++j){
			cout << b[i][j] << endl;
		}
	}
	return 0;
}