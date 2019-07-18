#include"stdafx.h"
//括号匹配的检验程序
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;


stack <char> a;

//符号检验函数
void check_symbol(char *string)
{
	int i, b;
	a.push(string[0]);
	for (i = 1; i<(b = (int)strlen(string)); i++)
	{
		//遍历每一个元素，判断出栈还是入栈
		if (!a.empty() && ((string[i] == ']'&&a.top() == '[') || (string[i] == ')'&&a.top() == '(')))//出栈的条件
		{
			a.pop();
		}
		else
		{
			a.push(string[i]);
		}
	}
	if (a.empty())
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
}



int main()
{
	int n;
	int i = 0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i != n; i++){
		char s[128] = { '\0' };
		//scanf("%s", s);
		gets(s);
		int b = (int)strlen(s);
		if (!b) {
			printf("Yes\n"); 
		}
		else{
			
			if (b % 2) { printf("No\n"); continue; }
			check_symbol(s);
			while (!a.empty()) a.pop();
		}
		
	}//for
	return 0;
}
