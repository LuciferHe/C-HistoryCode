/*
题目大意：
每个case 第一行 n,m(n表示接下来有n个网址依次被访问,m表示cache的最大容量) n=m=0结束
如果当前要访问的网址 cache里有，则输出"Cache"+换行, 该网址当前访问的次数加1;否则输出"Internet"+换行,并把当前网址加入到cache里去
如果新增的时候cache满了，则把cache里访问次数最少且是该相同次数里最早被访问的网址 扔掉，再把新网址加入进来。
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define DEBUG 0
#define DEBUG1 1
#define DEBUG2 0

#define mem(a) memset(a, 0, sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
const int MAXN = 20005;
const double EPS = 1e-9;
const double OO = 1e15;
//const double PI = acos(-1.0); //M_PI; cmath

vector<vector<string> > V(MAXN);//空格很重要
map<string, int> MP;
int n, m;
int ct;

inline void init(){
	int i;
	ct = 0;
	MP.clear();
	for (i = 0; i < MAXN; ++i)V[i].clear();
}
int dblcmp(double d){// -1:d<0; 1:d>0; 0:d=0 用来比较两个浮点数大小
	return d < -EPS ? -1 : d > EPS;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int i, j, t, cas=0;
	while (cin >> n >> m && (n || m)){
		init();
		cout << "Case " << ++cas << ": " << endl << endl;
		t = 0;
		while (t++ < n){
			string str;
			cin >> str;
			if (!MP.empty()){
				if (MP.count(str)){
					int x = MP[str];
					MP[str] += 1;
					auto index = find(V[x].begin(), V[x].end(), str);//在vector里查找str，返回该值所处的迭代器
					V[x].erase(index);//根据迭代器删除vector里面某个元素，其后的元素自动往前挪一位
					V[x + 1].push_back(str);
					cout << "Cache" << endl;
				}//cache 里有
				else{
					if (MP.size() == m){
						for (i = 0; i < MAXN; ++i)if (!V[i].empty()){
							if (DEBUG1){
								cout << "Erase:" << V[i][0] << endl;
							}
							MP.erase(V[i][0]);//map根据key删除元素
							V[i].erase(V[i].begin());
							break;
						}
					}//Cache 满了
					MP[str] = 0;
					V[0].push_back(str);
					cout << "Internet" << endl;
				}
			}//map非空
			else{
				cout << "Internet" << endl;
				V[0].push_back(str);
				MP[str] = 0;
			}
		}//while
	}

	return 0;
}