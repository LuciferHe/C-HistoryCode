#include"stdafx.h"
#include <iostream> 
using namespace std;
void main()
{
	cout << "第一章" << endl;
	cout << "    ";
	cout.setf(ios::left);        //设置对齐方式为left 
	cout.width(7);               //设置宽度为7，不足用空格填充 
	cout << "1.1";
	cout << "什么是C语言";
	cout.unsetf(ios::left);      //取消对齐方式，用缺省right方式 
	cout.fill('.');              //设置填充方式 
	cout.width(30);              //设置宽度，只对下条输出有用 
	cout << 1 << endl;
	cout << "    ";
	cout.width(7);               //设置宽度 
	cout.setf(ios::left);        //设置对齐方式为left 
	cout.fill(' ');              //设置填充，缺省为空格 
	cout << "1.11";
	cout << "C语言的历史";
	cout.unsetf(ios::left);      //取消对齐方式 
	cout.fill('.');
	cout.width(30);
	cout << 58 << endl;
	cout.fill(' ');
	cout << "第二章" << endl;
}

