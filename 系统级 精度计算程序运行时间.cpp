//C++高精度实现计算程序运行时间
#include<iostream>
#include<windows.h>

using namespace std;

void Test()//测试程序   
{
	int k = 0;
	for (int i = 0; i<1000; i++)
	{
		for (int j = 0; j<100; j++)
		{
			k++;
		}
	}
}

int main(void)
{
	LARGE_INTEGER BegainTime;
	LARGE_INTEGER EndTime;
	LARGE_INTEGER Frequency;
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&BegainTime);

	//要测试的代码放在这里    
	Test();

	QueryPerformanceCounter(&EndTime);

	//输出运行时间（单位：s）    
	cout << "运行时间（单位：s）：" << (double)(EndTime.QuadPart - BegainTime.QuadPart) / Frequency.QuadPart << endl;

	system("pause");
	return 0;
}