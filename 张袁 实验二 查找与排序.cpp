# include<stdio.h>
# include<string.h>
#include<windows.h>


const int MAXN = 1000 + 10;

static unsigned int next = 1;  //为产生随机数用的
#define DEBUG 1
unsigned int countCompareQ = 0; //记录快速排序比较次数
unsigned int countMoveQ = 0;    //记录快速排序移动次数
LARGE_INTEGER BegainTime;  //开始时间
LARGE_INTEGER EndTime;    //结束时间
LARGE_INTEGER Frequency;  //频率

//------函数声明---------
void rand1();
void InsertSort(unsigned int* Array, int Num);
void QuickSort(unsigned int *a, int left, int right);
void ShellSort(unsigned int *ar, int begin, int end);
void test();
//------函数声明-END-----


void rand1(){
	int count;
	unsigned int seed;
	FILE* fp[6];
	fp[1] = fopen("data1.txt", "wt");  //文件指针名=fopen(文件名,使用文件方式);  wt----只写打开或建立一个文本文件，只允许写数据
	fp[2] = fopen("data2.txt", "wt");
	fp[3] = fopen("data3.txt", "wt");
	fp[4] = fopen("data4.txt", "wt");
	fp[5] = fopen("data5.txt", "wt");
	printf("Please enter your choice for seed.\n");
	for (int i = 1; i <= 5; ++i){
		printf("请输入一个整数:");
		scanf("%u", &seed);
		next = seed;
		for (count = 0; count < 1000; count++){
			if (count == 500){ next = seed + 4; }//防止多次循环后next过大，影响随机效果
			next = next * 1103515245 + 12345;
			unsigned int t = ((next / 65536) % 32768) % 1232;
			fprintf(fp[i], "%u ", t);
		}
		fclose(fp[i]);
	}
}
void InsertSort(unsigned int* Array, int Num)
{
	/********************************************************
	*函数名称：InsertSort
	*参数说明：Array 无序数组；
	*		   Num为无序数据个数
	*说明：    插入排序
	*********************************************************/
	unsigned int countCompare = 0;
	unsigned int countMove = 0;
	for (int i = 1; i < Num; i++)    //从第2个数据开始插入
	{
		int j = 0;
		while (j < i && Array[j] <= Array[i])    //寻找插入的位置
		{
			j++;
			countCompare++;
		}

		if (j < i)    //i位置之前，有比Array[i]大的数，则进行挪动和插入
		{
			int k = i;
			unsigned int temp = Array[i];
			while (k > j)    //挪动位置
			{
				Array[k] = Array[k - 1];
				k--;
				countMove++;
			}
			Array[k] = temp;    //插入
		}
	}//for

	printf("插入排序比较次数:%u\n", countCompare);
	printf("插入排序移动次数:%u\n", countMove);
}
void QuickSort(unsigned int *a, int left, int right)  //从0开始
{
	/********************************************************
	*函数名称：QuickSort
	*参数说明：a 无序数组；
	*		   left为无序数组的最左边元素下标
	*		   right为无序数组的最右边元素下标
	*说明：    快速排序
	*********************************************************/

	int i = left;
	int j = right;
	unsigned int temp = a[left];
	if (left >= right)
		return;
	while (i != j)
	{
		while (i<j&&a[j] >= temp)
		{
			j--;
			countCompareQ++;
		}
		if (j>i)//a[i]已经赋值给temp,所以直接将a[j]赋值给a[i],赋值完之后a[j],有空位
		{
			a[i] = a[j];
			countMoveQ++;
		}

		while (i < j&&a[i] <= temp)
		{
			i++;
			countCompareQ++;
		}
		if (i < j)
		{
			a[j] = a[i];
			countMoveQ++;
		}
	}
	a[i] = temp;//把基准插入,此时i与j已经相等R[low..pivotpos-1].keys≤R[pivotpos].key≤R[pivotpos+1..high].keys
	QuickSort(a, left, i - 1);/*递归左边*/
	QuickSort(a, i + 1, right);/*递归右边*/
}
void ShellSort(unsigned int *ar, int begin, int end)  //从0开始
{
	/********************************************************
	*函数名称：ShellSort
	*参数说明：ar 无序数组；
	*		   begin为无序数组的最左边元素下标
	*		   end为无序数组的最右边元素下一位的下标
	*说明：    希尔排序
	*********************************************************/
	unsigned int countCompare = 0;
	unsigned int countMove = 0;
	int gap = end - begin + 1;    //gap初始值大于0
	while (gap > 1)
	{
		gap = gap / 3 + 1;    //当趟排序gap值确定
		for (int i = begin + gap; i < end; ++i)
		{
			unsigned int temp = ar[i];    //暂存关键数据
			int j = i;
			while (j - gap >= begin && temp < ar[j - gap])
			{
				ar[j] = ar[j - gap];   //后移
				j = j - gap;     //前置索引
				countCompare++;
				countMove++;
			}
			ar[j] = temp;   //插入关键数据
			countMove++;
		}
	}
	printf("希尔排序比较次数:%u\n", countCompare);
	printf("希尔排序移动次数:%u\n", countMove);
}
void test(){
	FILE* fp[6];
	const char txt[6][10] = { "", "data1.txt", "data2.txt", "data3.txt", "data4.txt", "data5.txt" };

	for (int i = 1; i <= 5; ++i){//5个随机数文件  各测一次
		fp[i] = fopen(txt[i], "rt");
		printf("数据文件data%d", i);
		printf(".txt测试\n\n");
		printf("----------------------------------------\n");
		unsigned int a[MAXN];
		unsigned int b[MAXN];
		for (int k = 0; k < 1000; ++k){
			fscanf(fp[i], "%u ", &a[k]);
		}
		fclose(fp[i]);
		memcpy(b, a, sizeof(a));
		for (int j = 1; j <= 3; ++j){//3中排序算法  各测一次
			switch (j)
			{
			case 1:{
					   QueryPerformanceFrequency(&Frequency);
					   QueryPerformanceCounter(&BegainTime);
					   InsertSort(a, 1000);
					   QueryPerformanceCounter(&EndTime);
					   printf("插入排序运行时间（单位：s）：%.6lf\n", (double)(EndTime.QuadPart - BegainTime.QuadPart) / Frequency.QuadPart);
					   break;
			}
			case 2:{
					   

					   QueryPerformanceFrequency(&Frequency);
					   QueryPerformanceCounter(&BegainTime);
					   countCompareQ = 0;
					   countMoveQ = 0;
					   QuickSort(a, 0, 999);
					   printf("快速排序比较次数:%u\n", countCompareQ);
					   printf("快速排序移动次数:%u\n", countMoveQ);
					   QueryPerformanceCounter(&EndTime);
					   printf("快速排序运行时间（单位：s）：%.6lf\n", (double)(EndTime.QuadPart - BegainTime.QuadPart) / Frequency.QuadPart);
					   break;
			}
			case 3:{
					   
					   QueryPerformanceFrequency(&Frequency);
					   QueryPerformanceCounter(&BegainTime);
					   ShellSort(a, 0, 1000);
					   QueryPerformanceCounter(&EndTime);
					   printf("希尔排序运行时间（单位：s）：%.6lf\n", (double)(EndTime.QuadPart - BegainTime.QuadPart) / Frequency.QuadPart);
					   break;
			}
			default: printf("Sort error!\n"); break;
			}
			/*
			switch (j)
			{
			case 1:{printf("\n\n\n插入排序完毕!结果如下：\n"); break; }
			case 2:{printf("\n\n\n快速排序完毕!结果如下：\n"); break; }
			case 3:{printf("\n\n\n希尔排序完毕!结果如下：\n"); break; }
			default:break;
			}
			int count = 0;
			for (int k = 0; k < 100; ++k){
			for (int K = 0; K < 10; ++K){
			printf("%d  ", a[count++]);
			}
			printf("\n");
			}*/
			memcpy(a, b, sizeof(b));
		}
	}
}
int main(){
	rand1();  //产生随机数，并存入文件data.txt中
	test();
	return 0;
}