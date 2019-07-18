//#include"stdafx.h"
#include<iostream>

using namespace std;

class ex
{
private:
	int value;
public:
	void set(int n);
	int get(void);
};
int ex::get(void)
{
	return value;
}
void ex::set(int n)  //关键是这里，编译器老是出错
{
	value = n;
}
int main()
{
	ex a, exarray[10];
	a.set(100);
	cout << "a.get()=" << a.get() << endl;
	for (int b = 0; b<9; b++)
	{
		exarray[b].set(b);
	}
	exarray[9].set(53);
	for (int c = 0; c<10; c++)
	{
		cout << "exarray[" << c << "]=" << exarray[c].get() << endl;
	}
	return 0;
}