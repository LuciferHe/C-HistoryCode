#include <iostream>
#include <string>
#include <stack>
using namespace std;

int fib(int n)//计算2的多少次方
{
	int sum = 1;
	if (n == 0)
		return 1;
	else
	{
		for (int i = 1; i <= n; i++)
			sum *= 2;
		return sum;
	}
}

string str[11];

int two[400008];//因为16进制的位数不超过100000，所以换成二进制数位数不超过400000

int main()
{
	int n, i, j, k;
	cin >> n;
	for (int k = 1; k <= n; ++k)
	{
		cin >> str[k];
		memset(two, 0, sizeof(two));
		for (i = 0; i<str[k].length(); ++i)//把十六进制的每一位变成4个二进制数，注意存放的顺序
		{
			if (str[k][i] >= '0'&&str[k][i] <= '9')
			{
				int temp = str[k][i] - '0';
				int tap = 4 * (i + 1);//把two数组每4个元素为一组，连续，当前的十六进制位为two数组的最大下标+1
				while (temp)
				{
					two[--tap] = temp % 2;//首先要tap-1，因为two数组是从0开始的，这也解释了为什么上面说是最大下标+1
					temp /= 2;
				}
			}//if
			else
			{
				int temp = str[k][i] - 55;//A-55得10
				int tap = 4 * (i + 1);
				while (temp)
				{
					two[--tap] = temp % 2;
					temp /= 2;
				}
			}//else
		}
		//到目前为止把16进制转成了二进制


		int count = 0;//二进制数三位一组来转化为8进制
		int sum = 0;//连续三位二进制数的值
		stack<int>q;
		for (j = 4 * str[k].length() - 1; j >= 0; --j)//从two数组的存数的最大下标开始处理，每三个为一组，转化为8进制，保存在栈中
		{
			sum += (two[j] * fib(count++));
			if (count == 3)
			{
				q.push(sum);
				sum = 0;
				count = 0;
			}

		}//for
		int sum1 = 0;//考虑处理的末尾，可能最后一组少于3个，有可能是一个，也可能是两个，单独处理，单独输出
		int c = 0;
		for (int m = 4 * str[k].length() % 3 - 1; m >= 0; --m)//4*str[k].length()%3判断还剩下几个
		{
			sum1 += two[c++] * fib(m);
		}
		if (sum1 != 0)
			cout << sum1;//单独输出
		else{
			if (q.top() == 0)
				q.pop();//去除前导0，如果有的话
		}
		while (!q.empty())
		{
			cout << q.top();//从栈中输出
			q.pop();
		}
		cout << endl;
	}
	return 0;
}
