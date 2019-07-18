#include<stdio.h>
#include<string.h>
using namespace std;
#define DEBUG 0
#define DEBUG1 0
#define DEBUG2 0

#define mem(a) memset(a, 0, sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

const int MAXN = 256;
const int MAXM = 100;

int arr[MAXN];
char sin[MAXM];
int sout[MAXM];
int len;
int kind;
int sum;

void init(){
	sum = 0;
	kind = 0;
	mem(arr);
	mem(sout);
	for (int i = 0; i < len; ++i){
		++arr[sin[i]];
		if (arr[sin[i]] == 1)kind++;
	}
	if (DEBUG){
		for (int i = 0; i < MAXN; ++i){
			if (arr[i]){
				printf("%c:  %d\n",(char)i,arr[i]);
			}
		}
		printf("\n\nKind:  %d\n\n",kind);
	}//ifDEBUG
}//init

void output(){
	++sum;
	printf("%d: ",sum);
	for (int i = 0; i < len; ++i){
		printf("%c",sout[i]);
	}
	printf("\n\n\n");
}
void f(int k){
	if (k == len){ output(); return; }
	int i,j;
	for (i = 1; i < MAXN; ++i){
		if (arr[i]){
			if (kind == 1){
				for (j = 0; j < arr[i]; ++j) sout[k + j] = i;
				output();
				return;
			}//只剩一种
			else{
				--arr[i];
				if (arr[i] == 0) --kind;
				sout[k] = i;
				f(k+1);
				sout[k] = 0;
				if (arr[i] == 0) ++kind;
				++arr[i];
			}
		}//if
	}//for
}//f

int main()
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", sin);
	len = strlen(sin);
	init();
	f(0);
	return 0;
}
