/*
思路：利用动态规划解决
d[i][j]表示从i到j的范围内最少需要添加的括号数
pos[i][j]表示i到j的范围内从pos[i][j]处分开进行添加可使得括号数最小，为-1表示无需分开添加
若s[i]和s[j]组合为"()"或"[]",则说明已经配对，只需处理i和j内部的序列，且暂时令pos[i][j]=-1；
然后枚举i到j中的分界点，查看是否存在k使得d[i][j]>d[i][k]+d[k+1][j]（状态转移方程），若存在，
则说明将i和j从k处分离成两部分进行处理可使得添加的括号数更小，此时令pos[i][j]=k，记录下此分界点

show函数说明：利用递归输出匹配后的括号序列
1、如果i>j，越界，则返回
2、如果i==j，说明只处理的一个括号，输出对应的配对括号对即可
3、如果i<j，首先判断pos[i][j]?-1，若相等，说明i和j之间无需分解，
先输出左边，然后递归输出中间，最后输出右边括号；若不相等，则递归
输出i到pos[i][j]，pos[i][j]+1到j两部分.
*/


#include<iostream>
using namespace std;
#define N 105
#define INF 1e9
int d[N][N];
int pos[N][N];
char s[N];  //接受初始数据
void Match(int len)
{
  int i, j, k;
  for (i = 0; i<len; i++)
    d[i][i] = 1;
  for (k = 1; k<len; k++)   //表示i和j之间的间隔
    for (i = 0; i<len - k; i++)
    {
    char right = s[i + k];
    char left = s[i];
    d[i][i + k] = INF;  //此条语句不能少，假如下面的if不执行，则for中判断就会出错d[i][i+k]未赋值
    if (left == '('&&right == ')' || left == '['&&right == ']')
    {
      d[i][i + k] = d[i + 1][i + k - 1];
      pos[i][i + k] = -1;
    }
    for (j = i; j<i + k; j++) //靠左分界
      if (d[i][i + k]>d[i][j] + d[j + 1][i + k])
      {
      pos[i][i + k] = j;
      d[i][i + k] = d[i][j] + d[j + 1][i + k];
      }
    }
}
void show(int i, int j)
{
  if (i>j)  return;
  if (i == j)
  {
    if (s[i] == '(' || s[i] == ')') cout << "()";
    else      cout << "[]";
  }
  else
  {
    if (pos[i][j] == -1)
    {
      cout << s[i];
      show(i + 1, j - 1);
      cout << s[j];
    }
    else
    {
      show(i, pos[i][j]);
      show(pos[i][j] + 1, j);
    }
  }
}

int main()
{
  cin >> s;
  int len = strlen(s);
  Match(len);
  show(0, len - 1);
  cout << endl << d[0][len - 1] + len << endl;
  return 0;
}