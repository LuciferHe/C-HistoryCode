#include <stdio.h>
#include <string.h>
#define MAX_LEN 101
int an1[MAX_LEN];
int an2[MAX_LEN];
int tmpAn2[MAX_LEN];
int anResult[MAX_LEN];
char szLine1[MAX_LEN];
char szLine2[MAX_LEN];
char szNouse[MAX_LEN];
void Substract( int nMaxLen, int * an1, int * an2)
//大整数an1减去an2。两者最多 nMaxLen 位，an1必须不小于an2, 差放在an1里
{
    int nStartPos = 0;
    int i;
    for( i = 0;i < nMaxLen ; i ++ ) 
    {    
        an1[i] -= an2[i];        //逐位相减
        if( an1[i] < 0 )
        {                   //看是否要进位    
            an1[i] += 10;
            an1[i+1] --;    //进位
        }
    }
}
void ShiftLeft( int nMaxLen,int * an2, int * tmpAn2, int n)
//将大整数an2左移n位，即乘以10的n次方，结果放到tmpAn2里
{
    int i;
    memcpy( tmpAn2,an2,nMaxLen * sizeof(int));
    if( n <= 0 )
        return;
    for( i = nMaxLen -1 ; i >= 0; i -- )
        if( i - n >= 0)
            tmpAn2[i] = an2[i-n];
        else
            tmpAn2[i] = 0;
}
int  Max(int nMaxLen, int * an1, int * an2)
//求大整数an1和an2中的数值大小
{

    int i;
    for( i = nMaxLen -1; i >= 0 ; i -- ) 
    {
        if( an1[i] > an2[i] )
            return 1;   //说明an1大
        else if( an1[i] < an2[i] )
            return -1;   //说明an2大
        
    }
    return 0;     //说明相同
}
int main()
{
    int n;
    int i, j;
    int nLen1,nLen2,nHighestPos,nShiftLen;
    scanf("%d",&n);
    gets(szNouse);
    while (n>0)
    {
        gets(szLine1);
        gets(szLine2);
            
        //库函数memeset将地址an1开始的sizeof(an1)字节内容置成0,sizeof(an1)的值就是an1的长度,memset函数在string.h中声明
        memset( an1, 0, sizeof(an1));    
        memset( an2, 0, sizeof(an2));
        //下面将szLine1,szLine2中存储的字符串形式的整数转换到an1,an2中去，an1[0],an2[0]对应于个位
        nLen1 = strlen( szLine1);
        for(j = 0, i = nLen1 - 1;i >= 0 ; i --)
            an1[j++] = szLine1[i] - '0';    
        nLen2 = strlen(szLine2);
        for( j = 0, i = nLen2 - 1;i >= 0 ; i --)
            an2[j++] = szLine2[i] - '0';
        nHighestPos = 0;
        memset(anResult,0,sizeof(anResult));
        nShiftLen=nLen1-nLen2;
        while( Max(MAX_LEN,an1,an2) >=0 )      //只要an1大于an2，就不停相减
        {
            //算出an1的10的nShiftLen次方倍
            ShiftLeft(MAX_LEN, an2, tmpAn2,nShiftLen);
            //重复减去an1的10的nShiftLen次方倍，看能减几次
            while( Max(MAX_LEN,an1,tmpAn2) >=0 ) 
            {
                Substract(MAX_LEN, an1,tmpAn2);
                anResult[nShiftLen] ++;   //记录商对应位
            } 
            if( nHighestPos == 0 && anResult[nShiftLen])
                nHighestPos = nShiftLen;          //记录结果最高位的位置
            nShiftLen --;
        }
        for( i = nHighestPos; i >= 0; i -- ) 
            printf("%d", anResult[i]);
        printf("\n");
        if (n>1)
            gets(szNouse);
        n--;
    }
    return 0; 
}