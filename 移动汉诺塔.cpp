//#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h> 
#include<iostream>

using namespace std;

	struct T
	{
		int h;      //塔的高度  
		int x;      //塔的第一个盘的x坐标 ,y坐标等于(7+n-塔的高度h)  
		int l;      //塔的第一个盘的长度   
	}ta[3] = { { 10, 15, 2 }, { 0, 0, 0 }, { 0, 0, 0 } };
	char  c[18][79], hnt[18][79] = {
		{ "                                                                              " },
		{ "                                 汉诺塔动画演示                               " },
		{ "                                                                              " },
		{ "  ╔════════════════════════════════════╗" },
		{ "  ║                                                                        ║" },
		{ "  ║                                                                        ║" },
		{ "  ║                                                                        ║" },
		{ "  ║           ▆                                                           ║" },
		{ "  ║          ▆▆                                                          ║" },
		{ "  ║         ▆▆▆                                                         ║" },
		{ "  ║        ▆▆▆▆                                                        ║" },
		{ "  ║       ▆▆▆▆▆                                                       ║" },
		{ "  ║      ▆▆▆▆▆▆                                                      ║" },
		{ "  ║     ▆▆▆▆▆▆▆                                                     ║" },
		{ "  ║    ▆▆▆▆▆▆▆▆                                                    ║" },
		{ "  ║   ▆▆▆▆▆▆▆▆▆                                                   ║" },
		{ "  ║  ▆▆▆▆▆▆▆▆▆▆                                                  ║" },
		{ "  ╚════════════════════════════════════╝" } };


	int n;
	int sum = 0;
	int computerorpeople = 1;
	int speed = 0;
	void count_ta_1(int ta_1)//重新计算塔的第一个盘的x坐标和塔的高度
	{
		int i;
		int j;
		int k = 0;
		for (i = 7; i<7 + n; i++)
		for (j = 4 + ta_1 * 24; j<28 + ta_1 * 24; j++)
		{
			if (hnt[i][j] != ' ')
			{
				for (; hnt[i][j + k] != ' '; k++);
				ta[ta_1].x = j;
				ta[ta_1].l = k;
				return;
			}
		}
	}

	void move(int ta_1, int ta_3)
	{
		int i;  sum++;
		ta[ta_3].h++;
		ta[ta_3].x = ta[ta_1].x + (ta_3 - ta_1) * 24;//每个塔之间相隔4
		ta[ta_3].l = ta[ta_1].l;
		for (i = 0; i<ta[ta_1].l; i++)
		{
			hnt[7 + n - ta[ta_3].h][ta[ta_3].x + i] = hnt[7 + n - ta[ta_1].h][ta[ta_1].x + i];
			hnt[7 + n - ta[ta_1].h][ta[ta_1].x + i] = ' ';
		}
		ta[ta_1].h--;
		count_ta_1(ta_1);
		system("cls");  for (i = 0; i<7 + n; i++)
			cout << hnt[i] << endl;
		cout << hnt[17];
		cout << endl << endl << "   从" << char(ta_1 + 65) << "塔移动一个盘到" << char(ta_3 + 65) << "塔" << endl;
		cout << endl << "   步数:" << sum << endl << endl;
		if (computerorpeople == 2)
			system("pause");
		else
		for (i = 0; i<200000 * speed; i++);
	}

	void hanoi(int ta_1, int ta_2, int ta_3, int m) //递归,ta_1/ta_2/ta_3分别为3座塔的代号，m为盘子数
	{
		if (m == 1)
			move(ta_1, ta_3);      //如果盘子为1，将这个盘子从塔座A移动到塔座C   
		else
		{
			hanoi(ta_1, ta_3, ta_2, m - 1);   //将塔座A的前m-1个盘子移到塔座B       
			move(ta_1, ta_3);      //将塔座A的第m个盘子移到塔座C     
			hanoi(ta_2, ta_1, ta_3, m - 1);   //将塔座B的m-1个盘子移到塔座C   
		}
	}


	void main() {
		int i, b = 1;
		for (i = 0; i<18; i++)
		{
			for (int j = 0; j <= 78; j++)
			{
				c[i][j] = hnt[i][j];
			}
		}
		while (b == 1)
		{
			cout << "请输入汉诺塔的高度：";
			cin >> n;
			cout << "请选择：输入1由电脑自动控制;" << endl;
			cout << "        输入2由人控制。" << endl;
			cout << "请输入：";
			cin >> computerorpeople;
			if (computerorpeople != 1 && computerorpeople != 2)
				computerorpeople = 1;
			if (computerorpeople == 1)
			{
				cout << "请输入移动盘的速度(例如：输入1000则代表1秒)：";
				cin >> speed;
			}
			if (n<1 || n>10)
				n = 10;
			ta[0].h = n;
			system("cls");//清除屏幕  
			for (i = 0; i<7 + n; i++)
				cout << hnt[i] << endl;
			cout << hnt[17] << endl;
			system("pause");// system("pause")就是从程序里调用"pause"命令;
			//而"pause"这个系统命令的功能很简单，就是在命令行上输出一行类似于"Press any key  to  exit"的字，等待用户按一个键，然后返回。 
			hanoi(0, 1, 2, n);
			if (computerorpeople == 1)
				system("pause");
			system("cls");
			for (i = 0; i<18; i++)
			{
				for (int j = 0; j <= 78; j++)
				{
					hnt[i][j] = c[i][j];
				}
			}
			cout << "是否继续游戏,是请按1，不是请按2" << endl;
			cin >> b;
			sum = 0;
			ta[0].h = 10;
			ta[0].l = 2;
			ta[0].x = 15;
			for (i = 1; i<3; i++)
			{
				ta[i].h = 0;   ta[i].l = 0;   ta[i].x = 0;
			}
		}
	}
