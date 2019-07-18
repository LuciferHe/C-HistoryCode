#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<cstdlib>

#define    NULL    0
#define    MAX    20
#define    TRUE    1
#define    FALSE    0

typedef    struct    tagstack{
	//定义一个双向栈
	int *    pStack;//栈底 同base指针
	int    lefttop;//左栈栈顶
	int    righttop;//右栈栈顶
}STACK;

void    menu();
void    choose(STACK *S, int a);
void    InilStack(STACK * S);
int    EmptyStack(STACK S);
int    FullStack(STACK S);
void    PushStack(STACK    *S, int    e);
int    PopStack(STACK    *S, int*    e);
void    ClearStack(STACK *S);
int    GetData(STACK    S, int*    e);//函数声明

void    main(){
	//主函数
	int    x = 0;
	STACK    S;//定义双向栈
	while (1)
	{
		menu();//清屏并显示菜单
		scanf("%d", &x); getchar();//输入选项吸收回车符
		if (x<1 || x>8)    printf("\nThe number you entry in is wrong!\n");//若输入的不是选项 提示出错
		else    if (x == 8) break; else choose(&S, x);//选择为8则退出 否则进行其他操作
		printf("\nPress any key to continue..."); getchar();
	}
}

void    menu(){
	//菜单函数
	printf("\n");
	printf("\n      ===================================================================");
	printf("\n     |                                                                   |");
	printf("\n     |   Welcome!Here is the menu..                                      |");
	printf("\n     |   1.  Create a stack;                                             |");
	printf("\n     |   2.  Clear a stack;                                              |");
	printf("\n     |   3.  Push into stack;                                            |");
	printf("\n     |   4.  Pop from stack                                              |");
	printf("\n     |   5.  Diagnose empty;                                             |");
	printf("\n     |   6.  Diagnose full;                                              |");
	printf("\n     |   7.  Get data;                                                   |");
	printf("\n     |   8.  exit.                                                       |");
	printf("\n     |                                                                   |");
	printf("\n      ===================================================================");
	printf("\n\nPlease choose which to do:      ");
}

void    choose(STACK *S, int a){
	int x = a, e = 0;
	static int flag = 0;
	if (!flag&&x != 1) { printf("Please create a stack first!!\n"); return; }//若为初始化且选择其他操作 提示错误
	switch (x)
	{
	case 1:    InilStack(S); flag = 1; break;//初始化双向栈 若以初始化 标记1
	case 2:    ClearStack(S); break;//清空双向栈
	case 3:    printf("Please input the data:");//输入要插入的数据
		scanf("%d", &e); getchar(); PushStack(S, e); break;//插入数据
	case 4:    if (PopStack(S, &e)) printf("The data you delete is %d.\n", e); break;//若删除元素成功 则显示所删除的数据
	case 5:    if (EmptyStack(*S))    printf("The stack is empty.\n", x);//输出双向栈为空
			   else printf("The stack is not empty.\n"); break;
	case 6:    if (FullStack(*S))    printf("The stack is full.\n", x);//输入栈满
			   else printf("The stack is not full.\n"); break;
	case 7:    if (GetData(*S, &e))printf("The data is %d.\n", e); break;//若获取元素成功 则显示所删除的数据
	}
}

void    InilStack(STACK * S){
	//构造一个空的双向栈
	(*S).pStack = (int *)malloc(sizeof(int)*MAX);//为双向栈分配内存
	if (!(*S).pStack)    { printf("Error!\n"); return; }//分配内存不成功 返回错误
	(*S).lefttop = -1;//左栈栈顶赋为-1
	(*S).righttop = MAX;//右栈栈顶赋为MAX
	printf("Stack initialized success..\n");//显示初始化成功
}

int    EmptyStack(STACK S){
	//判断双向栈是否为空栈 初始条件：双向栈S存在
	if ((S.lefttop == -1) && (S.righttop == MAX)) return    TRUE;
	return    FALSE;
}

int    FullStack(STACK S){
	//判断双向栈是否为满栈 初始条件：双向栈S存在
	if (S.lefttop == S.righttop - 1) return    TRUE;
	return    FALSE;
}

void    PushStack(STACK    *S, int    e){
	//插入元素为e为新的栈顶元素 初始条件：双向栈S存在
	char    a;
	if (FullStack(*S))    { printf("Stack full!!\n"); return; }//栈满 不能插入 返回
	printf("Right or Left?(r/l)");
	scanf("%c", &a);//选择左栈或右栈
	getchar();
	switch (a)
	{
	case 'r':case 'R':
		(*S).righttop--;
		*((*S).pStack + (*S).righttop) = e;//将e插入右栈
		break;
	case 'l':case 'L':
		(*S).lefttop++;
		*((*S).pStack + (*S).lefttop) = e;//将e插入左栈
		break;
	default: printf("Character entried wrong!!\n"); return;
	}
	printf("Data pushed in..\n");
}

int    PopStack(STACK    *S, int*    e){
	//删除栈顶元素 并用e返回 初始条件：双向栈S存在
	char    a;
	if (EmptyStack(*S))    { printf("Stack empty!!\n"); return FALSE; }//栈空 不能删除 返回
	printf("Right or Left?");
	scanf("%c", &a);//选择左栈或右栈
	getchar();
	switch (a)
	{
	case 'r':case 'R':
		if ((*S).righttop == MAX) { printf("Right stack empty!!\n"); return FALSE; }//右栈为空 删除失败
		*e = *((*S).pStack + (*S).righttop);
		(*S).righttop++;//删除右栈栈顶元素
		break;
	case 'l':case 'L':
		if ((*S).lefttop == -1) { printf("Left stack empty!!\n"); return FALSE; }//左栈为空 删除失败
		*e = *((*S).pStack + (*S).lefttop);
		(*S).lefttop--;//删除左栈栈顶元素
		break;
	default: return FALSE;//删除失败
	}
	return    TRUE;//成功
}

void    ClearStack(STACK *S){
	//清空双向栈 初始条件：双向栈S存在
	(*S).lefttop = -1; (*S).righttop = MAX; printf("The stack has been cleared..\n");
}

int    GetData(STACK    S, int*    e){
	//获取栈顶元素 并用e返回 初始条件：双向栈S存在
	char    a;
	if (EmptyStack(S))    { printf("Stack empty!!\n"); return FALSE; }//栈空 无数据 返回
	printf("Right or Left?");
	scanf("%c", &a);//选择左栈或右栈
	getchar();
	switch (a)
	{
	case 'r':case 'R':
		if (S.righttop == MAX) { printf("Right stack empty!!\n"); return FALSE; }//右栈为空 获取失败
		*e = *(S.pStack + S.righttop);//获取右栈栈顶元素
		break;
	case 'l':case 'L':
		if (S.lefttop == -1) { printf("Left stack empty!!\n"); return FALSE; }//左栈为空 获取失败
		*e = *(S.pStack + S.lefttop);//获取左栈栈顶元素
	default: return FALSE;//获取失败
	}
	return    TRUE;
	}