#include"stdio.h"
#include"conio.h"
#include"string.h"
#include"stdlib.h"
void look();
void save();
void type();
int openl();
void see();
void welcome();
void search_name();
void search_number();
void order();
void append();
void del();
void orderAge();
void orderMath();



struct student       /*定义学生信息的结构体类型*/
{
	int num;
	char gender[8];
	int age;
	char name[21];
	int math;
	int English;
}stu[100];


int n = 0;

void save()  /*建立保存文件函数*/
{
	//	system("CLS");
	FILE *fp;    /*定义文件型指针*/
	int i;
	if ((fp = fopen("student.txt", "wb")) == NULL)   /*打开输出文件*/
	{
		printf("不能打开文件！\n");
		return;                            /*终止程序*/
	}
	for (i = 0; i<n; i++)    /*向student文件中写入信息*/
	if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
		printf("文件写入错误\n");
	fclose(fp);      /*关闭文件*/
	printf("\n\n\n\n\t\t\t学生信息保存成功!\n");
}

void append()
{
	int i,
		n1;
	FILE *fp;
	printf("\n\t\t输入你想添加的学生信息个数:");
	scanf("%d", &n1);
	for (i = 0; i<n1; i++)      /*输入每个学生的信息*/
	{
		printf("\n\t\t\t----------------\n");
		printf("\t\t\t学号（整数且最多9位数）:");
		scanf("%d", &stu[i].num);
		printf( "\n" );

		printf("\t\t\t性别（男或女）:");
		scanf("%s", &stu[i].gender);
		printf("\n");

		printf("\t\t\t年龄:");
		scanf("%d", &stu[i].age);
		printf("\n");

		printf("\t\t\t姓名（中/英,20个字符以内,名字中间不能有空格）:");
		scanf("%s", &stu[i].name);
		printf("\n");

		printf("\t\t\t数学（整数）:");
		scanf("%d", &stu[i].math);
		printf("\n");

		printf("\t\t\t英语（整数）:");
		scanf("%d", &stu[i].English);
		printf("\n");
	}
	n += n1;

	if ((fp = fopen("student.txt", "ab")) == NULL)   /*打开输出文件*/
	{
		printf("不能打开文件！\n");
		return;                            /*终止程序*/
	}
	for (i = 0; i<n1; i++)    /*向student文件中写入信息*/
	if (fwrite(&stu[i], sizeof(struct student), 1, fp) != 1)
		printf("文件写入错误\n");
	fclose(fp);      /*关闭文件*/
	printf("\n\n\n\n\t\t\t学生信息保存成功!\n");
	
}

void orderAge(){
		int i, j;
		char a;
		struct student temp;    /*声明结构体变量*/
		printf( "\n\t\t年龄从大到小排序如下：\n\n" );
		printf("\n\t\t\t%-10s%-10s%-10s%-10s%-10s%-10s\n", "学号", "性别", "年龄", "姓名", "数学", "英语");

		for (i = 0; i<n - 1; i++)  /*对数据进行排序*/
		{
			for (j = 0; j<n - 1 - i; j++)
			{
				if (stu[j].age<stu[j + 1].age)
				{
					temp = stu[j];
					stu[j] = stu[j + 1];
					stu[j + 1] = temp;
				}
			}
		}
		for (i = 0; i<n; i++)
		{
			printf("\n\t\t\t%-10d%-10s%-10d%-10s%-10d%-10d\n", stu[i].num, stu[i].gender, stu[i].age, stu[i].name, stu[i].math, stu[i].English);
		}

		save();
		
	}

void orderMath(){
	int i, j;
	char a;
	struct student temp;    /*声明结构体变量*/
	printf("\n\t\t高数成绩从高到低排序如下：\n\n");
	printf("\n\t\t\t%-10s%-10s%-10s%-10s%-10s%-10s\n", "学号", "性别", "年龄", "姓名", "数学", "英语");

	for (i = 0; i<n - 1; i++)  /*对数据进行排序*/
	{
		for (j = 0; j<n - 1 - i; j++)
		{
			if (stu[j].math<stu[j + 1].math)
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	for (i = 0; i<n; i++)
	{
		printf("\n\t\t\t%-10d%-10s%-10d%-10s%-10d%-10d\n", stu[i].num, stu[i].gender, stu[i].age, stu[i].name, stu[i].math, stu[i].English);
	}
	
//	getchar();
	
		save();
	
//	getchar();
}

int openl()  /*定义打开文件函数*/
{
	//system("CLS");
	int i;
	FILE *fp;
	if ((fp = fopen("student.txt", "rb")) == NULL)
	{
		printf("Cannot open file.\n");
		exit(0);
	}
	for (i = 0; !feof(fp); i++)
		fread(&stu[i], sizeof(struct student), 1, fp);
	fclose(fp);
	return(i - 1);
}

void look() {
	//system("CLS");
	int i;
	n = openl();
	printf("\n\t\t\t文件打开成功!\n\n");
	getchar();
	printf("\n\t\t\t%-10s%-10s%-10s%-10s%-10s%-10s\n", "学号", "性别", "年龄", "姓名", "数学", "英语");
	for (i = 0; i<n; i++)    /*输出所有的学生信息*/
	{
		printf("\n\t\t\t%-10d%-10s%-10d%-10s%-10d%-10d\n", stu[i].num, stu[i].gender, stu[i].age, stu[i].name, stu[i].math, stu[i].English);
	}
	
}



void type()  
{
	//system("CLS");
	int i,
		n1;    
	printf("\n\t\t输入你想输入的学生信息个数:");
	scanf("%d", &n1);
	for (i = 0; i<n1; i++)    
	{
		printf("\n\t\t\t----------------\n");
		printf("\t\t\t学号（整数且最多9位数）:");
		scanf("%d", &stu[i].num);
		printf("\n");

		printf("\t\t\t性别（男或女）:");
		scanf("%s", &stu[i].gender);
		printf("\n");

		printf("\t\t\t年龄:");
		scanf("%d", &stu[i].age);
		printf("\n");

		printf("\t\t\t姓名（中/英,20个字符以内,名字中间不能有空格）:");
		scanf("%s", &stu[i].name);
		printf("\n");

		printf("\t\t\t数学（整数）:");
		scanf("%d", &stu[i].math);
		printf("\n");

		printf("\t\t\t英语（整数）:");
		scanf("%d", &stu[i].English);
		printf("\n");

	}
	n += n1;
	
	save();
}

void main()        /*主函数即用户的操作界面*/
{
	int b, flag = 0;           /*声明局部变量*/
	int first = 1;
	while (1)                   /*循环输出以下信息*/
	{
		if (first) {
			printf("\n\t\t\t欢迎来到学生成绩管理系统!\n");
			printf("\n\t\t\t\t  张袁制作\n");
			printf("\t\t\t-------------------------------\n");
			printf("\t\t\t1.(初次)录入学生信息,请输入 1\n\n");   /*键入学生的信息*/
			first = 0;
		}
		else{
		printf("\n\t\t\t欢迎来到学生成绩管理系统!\n");
		printf("\n\t\t\t\t  张袁制作\n");
		printf("\t\t\t-------------------------------\n");
		printf("\t\t\t2.查看所有学生信息\n\n");   /*查看录入的学生信息*/
		printf("\t\t\t3.按年龄排序\n\n");  /*按姓名查看学生的信息*/
		printf("\t\t\t4.按高数成绩排序\n\n");  /*按学号查看学生的信息*/
		printf("\t\t\t5.增加学生信息\n\n");  /*按学号查看学生的信息*/
	
		printf("\t\t\t0.退出\n\n");  /*退出*/
		}
		printf("\t\t\t请输入你的选择:");
		
		scanf("%d", &b);
		switch (b)
		{
		case 1:type(); break; /*调用键入学生信息函数*/
		case 2:look(); break; /*调用查看函数*/
		case 3:orderAge(); break;  /*调用姓名查看函数*/
		case 4:orderMath(); break;  /*调用学号查看函数*/
		case 5:append(); break;  /*调用学号查看函数*/
		
		case 0:flag = 1; break;/*退出SWITCH语句*/
			//	default :printf("错误!");
		}
		if (flag) break;   /*如果选择0就退出循环*/
	}
}