/*
题目：http://hihocoder.com/contest/hiho59/problem/1

题解：http://hihocoder.com/contest/hiho59/solution/468743
*/


#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<deque>
#include<unordered_map>
#define time QAQ //为了避免与标识符重名
using namespace std;
int n, opl; char se[6];
void inc() { puts("Incorrect performance log"); exit(0); }
struct time {
	int x, y, z;
	void get() { scanf("%d:%d:%d", &x, &y, &z); }
	time operator-(time&b) {
		time rt{ x - b.x, y - b.y, z - b.z };//结构体牛逼初始化
		if (rt.z < 0)rt.z += 60, --rt.y;
		while (rt.y < 0)rt.y += 60, --rt.x;
		if (rt.x < 0) inc();
		return rt;
	}
}tmp, last;
struct utask {
	time t; string name;
	void print() { cout << name; printf(" %02d:%02d:%02d\n", t.x, t.y, t.z); }
};
stack<utask>pro; deque<utask>op; unordered_map<string, int>oploc;
int main() {
	string tn;
	cin >> n; if (n & 1)inc();
	while (n--) {
		cin >> tn; tmp.get();//这个办法好
		tmp - last;//操作符重载  还是少用为好
		scanf("%s", se);//cin和scanf竟然可以混着用，66666
		if (se[0] == 'S') {
			pro.push(utask{ tmp, tn });
			op.push_back(utask{ tmp, tn });
			oploc[tn] = opl++;
		}
		else {
			if (pro.empty() || tn != pro.top().name)inc();
			op[oploc[tn]].t = tmp - pro.top().t; //deque 也可以用下标方式访问
			pro.pop();
		}
		last = tmp;
	}
	if (!pro.empty())inc();
	for (auto&x : op)x.print();//牛逼遍历
}