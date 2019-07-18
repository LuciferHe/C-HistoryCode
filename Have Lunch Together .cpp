/*
题目：http://hihocoder.com/problemset/problem/1092?sid=534575
题解：纯属原创

#1092 : Have Lunch Together
时间限制:10000ms
单点时限:1000ms
内存限制:256MB
描述
Everyday Littile Hi and Little Ho meet in the school cafeteria to have lunch together. The cafeteria is often so crowded that two adjacent seats are hard to find.

School cafeteria can be considered as a matrix of N*M blocks. Each block can be empty or occupied by people, obstructions and seats. Little Hi and Little Ho starts from the same block. They need to find two adjacent seats(two seats are adjacent if and only if their blocks share a common edge) without passing through occupied blocks. Further more, they want the total distance to the seats is minimal.

Little Hi and Little Ho can move in 4 directions (up, down, left, right) and they can not move outside the matrix.

输入
Input cantains a single testcase.

First line contains two integers N, M, the length and width of school cafeteria.

The next is a matrix consists of N lines, each line containing M characters. Each character describe a block: '.' for empty block, 'P' for people, '#' for obstructions, 'S' for seats and 'H' for Little Hi and Little Ho's starting position.

10 <= N, M <= 100

输出
Output the minimal distance they need to move to reach two adjacent seats. If no such adjacent seats output a line "Hi and Ho will not have lunch." without quotes.

样例输入
10 10
##########
#...P##..#
#S#...#.P#
#S#..#...#
#...#.####
#.#...#.H#
##......##
#..P#..S.#
##.......#
##########
样例输出
25
*/


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<queue>
using namespace std;

#define mem(a) memset(a, 0, sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
const int MAXN = 105;
const int INF = 0x7fffffff;

typedef struct node{
	int x, y;
	node(int xx = 0, int yy = 0) :x(xx), y(yy){}
	void set(int xx, int yy){ x = xx; y = yy; }
	bool operator < (node const& A) const{
		return (x < A.x || (x == A.x && y < A.y));
	}
}Node;


Node Start;
queue<Node> Q;
int n, m;
int Ma[MAXN][MAXN];
int vis[MAXN][MAXN];
map<Node, int> MP;
int dirx[] = { 1, -1, 0, 0 };
int diry[] = { 0, 0, -1, 1 };

inline void init(){
	mem(Ma);
	mem(vis);
	MP.clear();
	while (!Q.empty())Q.pop();
}


int isIn(int x, int y){
	return (0 <= x && x < n && 0 <= y && y < m);
}

void add(int x, int y){
	int i;
	for (i = 0; i < 4; ++i){
		int tx = x + dirx[i];
		int ty = y + diry[i];
		if (isIn(tx, ty) && vis[tx][ty] == 0 && (Ma[tx][ty] == -1 || Ma[tx][ty] == -2)){
			Q.push(Node(tx, ty));
		}
	}
}

int cal(int x, int y){
	int i;
	int len = INF;
	for (i = 0; i < 4; ++i){
		int tx = x + dirx[i];
		int ty = y + diry[i];
		if (isIn(tx, ty) && Ma[tx][ty] >= 0){
			len = MIN(len, Ma[tx][ty] + 1);
		}
	}
	return len;
}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	int i, j;
	int tx, ty;
	scanf("%d%d", &n, &m);
	getchar();
	init();
	for (i = 0; i < n; ++i){
		for (j = 0; j < m; ++j){
			char c = getchar();
			switch (c)
			{
			case '.': Ma[i][j] = -1; break;
			case 'S': Ma[i][j] = -2; break;
			case 'H': Ma[i][j] = 0; Start.set(i, j); break;
			default: Ma[i][j] = -3; break;
			}
		}//for2
		getchar();
	}//for1
	vis[Start.x][Start.y] = 1;
	add(Start.x, Start.y);
	Node p;
	while (!Q.empty()){
		p = Q.front();
		Q.pop();
		vis[p.x][p.y] = 1;
		if (Ma[p.x][p.y] == -2){
			MP[Node(p.x, p.y)] = cal(p.x, p.y);
			for (i = 0; i < 4; ++i){
				tx = p.x + dirx[i];
				ty = p.y + diry[i];
				if (isIn(tx, ty) && MP.count(Node(tx, ty))){
					int ans = MP[Node(p.x, p.y)] + MP[Node(tx, ty)];
					printf("%d\n", ans);
					exit(0);//0 正常退出
				}
			}
		}//如为座位
		else{
			Ma[p.x][p.y] = cal(p.x, p.y);
			add(p.x, p.y);
		}
	}
	printf("Hi and Ho will not have lunch.\n");
	return 0;
}