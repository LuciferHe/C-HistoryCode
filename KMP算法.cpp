//http://www.cnblogs.com/dolphin0520/archive/2011/08/24/2151846.html
//若aaaab  的next值为{-1, -1, -1, -1, 3} 才算牛逼
//若next[j]=t，则p[0.....k-1]=p[j-k......j-1]  其中t代表：若匹配过程中在j位置失败，模式串变量跳到k位置
//上述表述为p[0.....n-1]成立
//若p[j]==p[k]，则next[j]=next[k]
//考试的时候求next的值   就拿这个程序的结果+1就OK
#include<stdio.h>
#include<string.h>

void getNext(char *p, int *next)
{
	int j, k;
	next[0] = -1;
	j = 0;
	k = -1;
	while (j<strlen(p) - 1)
	{
		if (k == -1 || p[j] == p[k])    //匹配的情况下,p[j]==p[k]
		{
			j++;
			k++;
			next[j] = k;
		}
		else                   //p[j]!=p[k]
			k = next[k];
	}
}
int KMPMatch(char *s, char *p)
{
	int next[100];
	int i, j;
	i = 0;
	j = 0;
	getNext(p, next);
	while (i<strlen(s))
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];       //消除了指针i的回溯
		}
		if (j == strlen(p))
			return i - strlen(p);
	}//while
	return -1;
}

int main(){
	char p[100] = { '\0' };
	char s[100] = { '\0' };
	int next[100] = { 0 };
	scanf("%s", p);
	scanf("%s", s);//s比p长
	getNext(p, next);
	int t = KMPMatch(s,p);
	printf("\nt is %d\n",t);
	//printf("\n%c %c %c\n", s[t-1],s[t],s[t+1]);
	for (int i = 0; i < strlen(p); ++i){
		printf("%d ", next[i]);
	}
	printf("\n");

	return 0;
}

